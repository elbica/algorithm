#include<bits/stdc++.h>
using namespace std;

//45도 반시계 회전 : (idx % 8) + 1 : 1 ~ 8 까지의 수
int dx[9] = {0,0,-1,-1,-1,0,1,1,1};
int dy[9] = {0,-1,-1,0,1,1,1,0,-1};
pair<int,int> adj[4][4]; //{번호, 방향}
pair<int,int> fish[17]; //물고기 좌표 저장

int func(int y, int x){
    //기저 : 범위를 벗어나 상어가 집에 갈 때
    if(y < 0 || y >= 4 || x < 0 || x >= 4) return 0;
    
    int answer = 0;
    pair<int,int> a[4][4], f[17];
    memcpy(f,fish,sizeof(fish));
    memcpy(a,adj,sizeof(adj));

    //1. 상어는 (y,x)의 물고기를 먹는다. 
    int ret = adj[y][x].first; //먹은 물고기 번호
    int direction = adj[y][x].second; //상어 방향

    fish[ret] = {-1,-1}; //먹힌 물고기의 좌표는 (-1,-1)로 설정.
    adj[y][x].second = -2; //상어가 있는 자리의 방향은 -2로 설정.

    //2. 물고기가 번호 순대로 이동한다
    for(int i=1; i<=16; i++){
        //현재 탐색 지점이 상어이거나, 먹힌 경우
        if(fish[i].first == -1) continue;
        bool flag = false;
        int count = 0, herey = fish[i].first, herex = fish[i].second;
        int& fDirect = adj[herey][herex].second;

        while(!flag){
            //이동할 때 까지 방향을 바꾼다.
            if(count == 8) break; //모든 방향 이동 불가
            if(flag) break; //이동 했을 때

            //이동할 곳의 좌표, 물고기 번호, 물고기 방향
            int newy = herey + dy[fDirect], newx = herex + dx[fDirect];
            int newnum = adj[newy][newx].first, newdirec = adj[newy][newx].second;
            
            //이동할 공간이 경계를 벗어났거나 상어인 경우 (방향이 -2 인지를 검사)
            if(newy >=4 || newy < 0 || newx >=4 || newx < 0 ||
                adj[newy][newx].second == -2) {
                    fDirect = (fDirect % 8) + 1; count++;
                    continue;
                }
            //정상적인 경우 swap.
            fish[i] = {newy, newx}; fish[newnum] = {herey,herex};
            adj[newy][newx].swap(adj[herey][herex]);
            flag = true;
        }
    }
    //3. 상어가 이동한다
    //원래 자리는 먹은 처리 (방향에 -1)를 한다
    adj[y][x].second = -1;

    //최대 3가지의 경우 발생. 그 중 가장 좋은 답을 고른다
    for(int i=1; i<=3; i++){
        int sharky = y + i * dy[direction], sharkx = x + i * dx[direction];

        //이미 먹힌 곳은 건너 뛴다
        if(adj[sharky][sharkx].second == -1) continue;
        answer = max(answer, func(sharky, sharkx) + ret);
    }
    //4. 맵과 물고기 상태를 원래대로 돌려 놓는다
    memcpy(adj,a,sizeof(a));
    memcpy(fish,f,sizeof(f));
    return answer;
}

int main(){
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++) {
            cin>>adj[i][j].first>>adj[i][j].second;
            fish[adj[i][j].first] = {i,j};
            }
   cout<< func(0,0);
}