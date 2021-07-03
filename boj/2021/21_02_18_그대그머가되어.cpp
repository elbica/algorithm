#include<bits/stdc++.h>
using namespace std;

int n,m,a,b;
bool adj[1001][1001];
int visited[1001];

int main(){
    //cout<<"?"<<endl;
    cin>>a>>b;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        adj[x][y] = true;
        adj[y][x] = true;
        
    }
    queue<int> q; 
    q.push(a);
    int count = 1;
    //cout<<"??"<<endl;
    while(!q.empty()){
        int qsize = q.size();
        for(int j=0; j<qsize; j++){
            int here = q.front(); q.pop();
        if(visited[here]) continue;
        visited[here] = count;
        
        for(int i=1; i<=n; i++)
            if(adj[here][i]) q.push(i);
        }
        count++;
    }
    if(visited[b]==0) cout<<-1<<endl;
    else cout<<visited[b]-1<<endl;
}