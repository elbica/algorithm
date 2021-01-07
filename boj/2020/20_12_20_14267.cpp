#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    int n, m; cin>>n>>m;
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    
    vector<vector<int>> adj(n+1,vector<int>());
    vector<int> good(n+1,0);

    //간선 거꾸로 연결
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x==-1) x = 0;
        adj[x].push_back(i);
    }
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        //칭찬 여러번 가능
        good[x]+=y;
    }
    queue<pair<int,int>> q;
    vector<bool> visited(n+1);
    vector<int> result(n+1);
    q.push({0,0});//사원 번호, 칭찬 점수
    while(!q.empty()){
        int here = q.front().first, score = q.front().second; q.pop();
        if(visited[here]) continue;
        visited[here]=true;
        result[here]=score;
        for(int c : adj[here]){
            q.push({c,score+good[c]});
        }
    }
    for(int i=1;i<=n;i++) cout<<result[i]<<' ';
    cout<<endl;
}
