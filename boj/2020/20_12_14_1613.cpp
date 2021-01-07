#include<iostream>
#include<algorithm>
#define INF 987654321
using namespace std;
int adj[401][401];
int result[401][401];
int n,k,s;
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>n>>k;
    //초기화
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) adj[i][j]=INF;

    //단방향 그래프
    for(int i=0;i<k;i++){
        int x,y; cin>>x>>y;
        adj[x][y]=1;
    }

    //플로이드 와샬 알고리즘
    //모든 정점 간 최단거리를 구한다
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(adj[i][k]+adj[k][j]<adj[i][j]) 
                    adj[i][j] = adj[i][k]+adj[k][j];
    cin>>s;
    for(int i=0;i<s;i++){
        int x,y; cin>>x>>y;
        if(adj[x][y]!=INF) cout<<-1<<'\n';
        else if(adj[y][x]!=INF) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
}