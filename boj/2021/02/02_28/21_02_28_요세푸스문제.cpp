#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    queue<int> q;
    cout<<"<";
    for(int i=1; i<=n; i++) q.push(i);
    while(!q.empty()){
        int temp = k;
        while(--temp){
            q.push(q.front()); q.pop();
        }
        cout<<q.front();q.pop();
        if(!q.empty())
        cout<<", "; 
    }
    cout<<">";
}