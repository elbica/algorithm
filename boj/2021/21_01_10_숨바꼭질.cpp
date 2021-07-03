//boj) 1697
#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> arr(200001,999999);

int main(){
    cin>>n>>k;
    
    queue<pair<int,int>> q;
    q.push({n,0}); //{시작 위치, 걸린 시간}

    while(!q.empty()){
        int here = q.front().first;
        int cost = q.front().second; q.pop();

        //이미 덜 걸린 경우가 계산되어 있으면 패스
        if(arr[here] <= cost) continue;
        arr[here] = cost;
        
        //1을 빼는 경우
        if(here - 1 >= 0 ) 
            q.push({here-1, cost+1});

        //1을 더하거나 2을 곱하는 경우
        //k 이상에서 더하거나 곱하는 것은 의미가 없다
        if(here < k) {
            q.push({here+1, cost+1});
            q.push({here*2, cost+1});
        }
        
    }
    cout<<arr[k];
}