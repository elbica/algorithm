#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        queue<pair<int,int>> inputs;
        priority_queue<int,vector<int>,less<int>> check;
        vector<int> answer(n);
        for(int i=0; i<n; i++) {
            int x; cin>>x;
            inputs.push({i,x}), check.push(x);
        }
        int count = 0;
        while(!inputs.empty()){
            auto here = inputs.front(); inputs.pop();
            if(here.second!=check.top()){
                inputs.push(here); continue;
            }
            answer[here.first] = ++count; check.pop();
        }
        cout<<answer[m]<<endl;
    }
    


}