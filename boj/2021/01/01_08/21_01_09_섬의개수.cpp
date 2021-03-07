#include<bits/stdc++.h>
using namespace std;

bool arr[50][50];
bool visited[50][50];
int plusX[8] = {1,0,-1,0,1,1,-1,-1};
int plusY[8] = {0,-1,0,1,1,-1,1,-1};
int n, m;

//하나의 섬을 탐색할 때마다 각각의 칸을 모두 방문 처리하여
//한 번만 탐색되도록 한다
bool bfs(int Y, int X){

    //이미 방문한 칸이거나
    if(visited[Y][X]) return false;
    //섬이 아니면 false 반환
    if(!arr[Y][X]) return false;
    queue<pair<int,int>> q;
    q.push({Y,X});

    while(!q.empty()){
        int hereY = q.front().first;
        int hereX = q.front().second;
        q.pop();
        if(visited[hereY][hereX]) continue;
        visited[hereY][hereX] = true;

        for(int i=0;i<8;i++){
            int newY = hereY + plusY[i];
            int newX = hereX + plusX[i];
            if(newY>=n || newY < 0 || newX >= m || newX < 0) continue;
            //상하좌우 대각선 중 섬인 칸만 큐에 넣는다
            if(arr[newY][newX]){
               q.push({newY,newX}); 
            } 
        }
    }
    //섬을 찾았으면 true 반환
    return true;
}
int main(){
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    while(true){
        memset(arr,false,sizeof(arr));
        memset(visited,false,sizeof(visited));
        cin>>m>>n;
        if(m==0 && n==0) break;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) cin>>arr[i][j];

        int Count = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(bfs(i,j)) Count++;
        cout<<Count<<'\n';
    }
}