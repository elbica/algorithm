#include<bits/stdc++.h>
using namespace std;

int result[2][3];
char adj[2][100][100];
bool visited[2][100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n;

void bfs(int y, int x){
    //정상인 경우, 적록색약인 경우 한번에 계산
    for(int i=0; i<2; i++){
        if(visited[i][y][x]) continue;

        queue<pair<int,int>> q;
        char check = adj[i][y][x];
        q.push({y,x});

        while(!q.empty()){
            int herey = q.front().first;
            int herex = q.front().second; q.pop();
            if(visited[i][herey][herex]) continue;
            visited[i][herey][herex] = true;
            for(int j=0; j<4; j++){
                int newy = herey + dy[j], newx = herex + dx[j];
                if(newy < 0 || newy >=n || newx < 0 || newx >= n ) continue;
                if(adj[i][newy][newx]==check) q.push({newy,newx});
            }
        }
        //적록 색약의 경우 G구역의 개수는 늘어나지 않는다
        if(check=='R') result[i][0]++;
        else if(check=='G') result[i][1]++;
        else if(check=='B') result[i][2]++;
    }
}
int main(){
    cin>>n;
    //적록 색약인 경우 G를 R로 변환
    for(int i=0;i<n;i++)
        for(int j=0; j<n; j++) {
            cin>>adj[0][i][j];
            adj[1][i][j] = adj[0][i][j];
            if(adj[1][i][j]=='G') adj[1][i][j] = 'R';  
        }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) bfs(i,j);
    
    cout<< result[0][0] + result[0][1] + result[0][2]<<' '
        <<result[1][0] + result[1][2]<<endl;
    
}
