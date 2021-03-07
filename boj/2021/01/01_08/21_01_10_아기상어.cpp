#include<bits/stdc++.h>
using namespace std;

int n, shark = 2, body = 0, t;
int arr[20][20];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

pair<int,int> bfs(int i, int j){
    vector<pair<int,int>> posi;
    queue<pair<int,int>> q;

    bool visited[20][20] = {0,}, flag = false;
    int check, level = 0;

    q.push({i,j});
    while(!q.empty()){
        //level별 탐색
        int qsize = q.size();
        for (int k = 0; k < qsize; k++){
            int hereY = q.front().first;
            int hereX = q.front().second; q.pop();
            
            if (visited[hereY][hereX]) continue;
                visited[hereY][hereX] = true;
            //먹을수 있는 물고기가 나타나면 벡터에 저장, 레벨(거리) 기록, 플래그 활성
            if(arr[hereY][hereX]!=0 && arr[hereY][hereX] < shark) {
                    flag = true; check = level;
                    posi.push_back({hereY,hereX});
            }
            for (int i = 0; i < 4; i++){
                int newY = hereY + dy[i];
                int newX = hereX + dx[i];
                if (newY < 0 || newY >= n || newX < 0 || newX >= n) continue;
                if(arr[newY][newX] <= shark) q.push({newY,newX});
            }
        }
        //하나의 레벨을 다 탐색하고, 물고기를 찾았으면 빠져나온다
        level++;
        if(flag) break;
    }
    //먹을 수 있는 물고기가 없으면 바로 리턴
    if(posi.size()==0) return {-1,-1};
    //정렬을 통해 위쪽 우선, 위쪽이 같으면 오른쪽 우선 구현 가능
    sort(posi.begin(), posi.end());
    int reti = posi[0].first, retj = posi[0].second;
    //물고기를 찾은 해당 레벨(거리)을 더한다
    t += check;
    return {reti,retj};
}
int main(){
    cin >> n;
    int paraY, paraX;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
            if(arr[i][j]==9){
                paraY = i; paraX = j;
            }
        }
    arr[paraY][paraX] = 0;
    //재귀를 사용하면 간단화 할 수 있어 보임
    while(true){
        //찾은 물고기 좌표
        auto posis = bfs(paraY, paraX);
        int nextY = posis.first, nextX = posis.second;
        //없으면 빠져나온다
        if(nextY==-1) break;

        //원래 자리를 0 으로 만들어 주고 상어 크기를 조건에 따라 키운다
        arr[nextY][nextX] = 0;
        if(++body==shark){ shark++; body = 0;}
        paraY = nextY; paraX = nextX;
    }
    cout<<t;
}