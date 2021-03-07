#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;
int check[10001], visited[10001];
int n, answer;

//백트래킹
void back(int here, int cost){
    //끝 점에 도달했을 때
    if(here == n+1){
        answer = max(answer,cost); return;
    }
    //이미 방문한 노드일 때
    if(visited[here]) return;

    visited[here] = true;

    for(auto child : adj[here]){
        //자식들에 대해 재귀 호출
        int newCost = cost + child.second;
        int next = child.first;
        back(next,newCost);
    }

    visited[here] = false;
}

int main(){
    //아이디어 : 시작 노드 0, 끝 노드 n+1을 만들어 리프 노드들과 연결시킨다
    //시작 노드에서 끝 노드까지 백 트래킹 기반 완전 탐색을 한다...

    //하지만 더 찾아보니 루트 노드 1에서 bfs를 돌려 1과 가장 멀리있는 노드를 찾고
    //그 노드에서 다시 한번 bfs를 돌려 최종적으로 가장 긴 경로를 찾을 수 있었다
    //두 번째 방식이 더 효율적이다
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    cin>>n;
    adj.resize(n+2);
    for(int i=0;i<n-1;i++){
        //양방향 간선 연결
        int x, y, z; cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z}); //{자식, 가중치}
        check[x]++; check[y]++;
    }
    for(int i=1; i<=n; i++){
        //리프 노드들 (루트 노드도 리프가 될 수 있다)
        if(check[i]==1){
            //탐색 시작 점 0, 끝나는 점 n+1, 단방향 간선 연결
            adj[0].push_back({i,0});
            adj[i].push_back({n+1,0});
        }
    }
    back(0,0);
    cout<<answer<<endl;
}
