#include<bits/stdc++.h>
using namespace std;

int main(){
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);

    int n, m;
    cin>>n>>m;
    //우선순위 큐 (최소 힙)
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        pq.push(x);
    }

    //가장 작은 수를 log(n) 복잡도로 탐색할 수 있다
    for(int i=0;i<m;i++){
        long long x = pq.top(); pq.pop();
        long long y = pq.top(); pq.pop();
        long long z = x+y;
        pq.push(z); pq.push(z);
    }
    long long answer = 0;
    while(!pq.empty()){
        answer+=pq.top(); pq.pop();
    }
    cout<<answer;
}