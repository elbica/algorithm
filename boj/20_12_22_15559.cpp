#include<bits/stdc++.h>
#include<iostream>
using namespace std;

char adj[1000][1000];
int N,M;
int visited[1000][1000];
int main(){
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) cin>>adj[i][j];

    int Count = 0, level = 1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            //방문한 점이면 패스
            if(visited[i][j]) continue;
            int hereX = j, hereY = i;
            bool skip = true;
            while(true){
                //1. 하나의 사이클이 만들어 질 때
                if(visited[hereY][hereX]==level) break;
                //2. 사이클 안으로 들어갈 때
                else if(visited[hereY][hereX]!=0){skip=false; break;}

                //몇 번째 phase인지 저장
                visited[hereY][hereX] = level;

                //좌표 변경
                if(adj[hereY][hereX]=='S') hereY++; 
                else if(adj[hereY][hereX]=='N') hereY--; 
                else if(adj[hereY][hereX]=='E') hereX++; 
                else if(adj[hereY][hereX]=='W') hereX--; 
            }
            //사이클이 만들어 질 때만 증가
            if(skip) Count++;
            level++;
        }
    }
    cout<<Count<<endl;
}