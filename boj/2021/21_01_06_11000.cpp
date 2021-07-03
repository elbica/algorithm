#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //끝나는 시간을 넣는다. 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq; 
    int n; cin>>n;
    vector<pair<int,int>> input(n);

    for (int i = 0; i < n; i++)
        cin >> input[i].first >> input[i].second;
    //시작 시간 기준 오름차순 정렬    
    sort(input.begin(), input.end()); 

    //아이디어 : 현재 idx 수업의 시작하는 시간이 pq의 끝나는 시간보다
    //1. 같거나 큰 경우 2. 작은 경우
    pq.push(input[0].second);
    for(int i=1; i<input.size();i++){
        int temp = pq.top();
        //1. 같거나 큰 경우 강의실을 계속 쓸 수 있다
        if(temp <= input[i].first){
            pq.pop(); pq.push(input[i].second);
        }
        //2. 작은 경우 강의실이 하나 더 추가된다
        else  pq.push(input[i].second);
        
    }
    cout<<pq.size();

}