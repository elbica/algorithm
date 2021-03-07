#include<bits/stdc++.h>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int input[500][500], n , m, Count, answer;
bool visited[500][500];

void bfs(int y, int x){
    
    if(!input[y][x]||visited[y][x]) return;
    visited[y][x] = true;
    queue<pair<int,int>> q;
    q.push({y,x});
    
    int check = 1;
    while(!q.empty()){
        int hereY = q.front().first, hereX = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nextY = hereY + dy[i], nextX = hereX + dx[i];
            if(nextY>=n || nextY<0 || nextX >=m || nextX<0) continue;
            if(input[nextY][nextX] && !visited[nextY][nextX]){
                visited[nextY][nextX] = true;
                q.push({nextY,nextX}); check++;
            }
        }
    }
    answer = max(answer,check);
    Count++;
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin>>input[i][j];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) bfs(i,j);
    cout<<Count<<'\n'<<answer<<endl;
}