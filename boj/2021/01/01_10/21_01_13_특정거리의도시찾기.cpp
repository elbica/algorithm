#include<bits/stdc++.h>
using namespace std;

int n,m,k,x;
vector<int> adj[300001];
vector<int> answer;

int main(){
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    cin>>n>>m>>k>>x;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
    }
    queue<int> q;
    q.push(x);
    bool visited[300001] = {};
    int level = 0;
//bfs -> 간선의 가중치가 동일 할 때, 최단거리를 구할 수 있음
    while(!q.empty()){
        //level 별 순회
        int qsize = q.size();
        for(int i=0; i<qsize; i++){
            int here = q.front(); q.pop();

            if(visited[here]) continue;
            visited[here] = true;

            //k level (최단거리가 k) 일 때 정점 저장
            if(level == k) answer.push_back(here);

            for(int c : adj[here]) q.push(c);
        }
        level++;
    }
    if(answer.size()==0) answer.push_back(-1);
    else sort(answer.begin(),answer.end());

    for(int a : answer) cout<<a<<'\n';
}