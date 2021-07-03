#include<bits/stdc++.h>
using namespace std;
int n,m;
bool adj[1001][1001];
int main(){
    int t; cin>>t;
    while(t--){
        memset(adj,0,sizeof(adj));
        cin>>n>>m;
        for(int i=0; i<m; i++){
            int x,y; cin>>x>>y;
            adj[x][y] = adj[y][x] = true;
        }
        queue<int> q;
        q.push(1);
        vector<bool> visited(n+1,false);
        visited[1] = true;
        int answer = 0;
        while(!q.empty()){
            int here = q.front(); q.pop();
            for(int i=1; i<=n; i++){
                if(adj[here][i] && !visited[i]){
                    visited[i] = true;
                    q.push(i); answer++;
                }
            }
        }
        cout<<answer<<endl;
    }

}