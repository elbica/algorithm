#include<bits/stdc++.h>
using namespace std;

bool arr[50][50];
bool visited[50][50];
int plusX[4] = {1,0,-1,0};
int plusY[4] = {0,-1,0,1};
int n, m;

//하나의 배추 밭을 탐색할 때마다 각각의 배추를 모두 방문 처리하여
//한 번만 탐색되도록 한다
bool bfs(int Y, int X){

    //이미 방문한 칸이거나
    if(visited[Y][X]) return false;
    //배추가 아니면 false 반환
    if(!arr[Y][X]) return false;
    queue<pair<int,int>> q;
    q.push({Y,X});

    while(!q.empty()){
        int hereY = q.front().first;
        int hereX = q.front().second;
        q.pop();
        if(visited[hereY][hereX]) continue;
        visited[hereY][hereX] = true;

        for(int i=0;i<4;i++){
            int newY = hereY + plusY[i];
            int newX = hereX + plusX[i];
            if(newY>=n || newY < 0 || newX >= m || newX < 0) continue;
            //상하좌우 중 배추인 칸만 큐에 넣는다
            if(arr[newY][newX]){
               q.push({newY,newX}); 
            } 
        }
    }
    //배추 밭을 찾았으면 true 반환
    return true;
}
int main(){
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    int T; cin>>T;
    while(T--){
        int k;
        memset(arr,false,sizeof(arr));
        memset(visited,false,sizeof(visited));

        cin>>m>>n>>k;
        for(int i=0;i<k;i++){
            int x,y; cin>>x>>y;
            arr[y][x] = true;
        }
        int Count = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(bfs(i,j)) Count++;
        cout<<Count<<'\n';
    }
}