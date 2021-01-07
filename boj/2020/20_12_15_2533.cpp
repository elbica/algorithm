#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int cache[1000001][2];
vector<int> adj[1000001];
vector<bool> visited(1000001);

//백트래킹 + dp
int dp(int here, bool version){
    //메모이제이션
    int& ret = cache[here][version];
    if(ret != -1) return ret;

    ret = 0;
    //백트래킹
    visited[here]=true;

    for(int& c : adj[here]){
        //방문 했다는 것은 부모 노드인 것이다. 건너뛴다.
        if(visited[c]) continue;

        //version 1 : 현재 노드가 얼리아답터일 때
        //자식 노드는 아무거나 되어도 상관 없다. 그 중 최소값을 고른다
        if(version){
            ret += min(dp(c,0), dp(c,1));
        }
        //version 0 : 얼리어답터가 아닐 때
        //자식 노드들은 모두 얼리어답터여야 한다
        else ret += dp(c,1);
    }
    if(version) ret++;

    //백트래킹
    visited[here]=false;

    return ret;
}
int sol(int v){
    return dp(1,v);
}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    memset(cache,-1,sizeof(cache));
    int n; cin>>n;

    for(int i=1;i<n;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<min(sol(0),sol(1))<<'\n';
}