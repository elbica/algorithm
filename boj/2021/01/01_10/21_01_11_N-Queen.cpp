#include<bits/stdc++.h>
using namespace std;

int n, answer;
int visited[15][15];
int dy[2] = {-1,1};

void queen(int y, int x, int version){
    //현재 좌표에 표시
    visited[y][x] += version;
    int y1 = y, y2 = y;

    for(int j = x+1; j<n; j++){
        //좌표 변경
        y1+=dy[0]; y2+=dy[1];
        //오른쪽 대각선 2개, 직선 표시
        if(y1 >= 0 && y1 < n ) visited[y1][j] += version;
        if(y2 >= 0 && y2 < n) visited[y2][j] += version;
        visited[y][j]+=version;
    }

}
//놓을 좌표, 이전에 퀸을 놓은 개수
void bf(int y, int x, int count){
    //놓을 수 없다면 리턴
    if(visited[y][x]) return; 
    //놓을 수 있는 현재 좌표를 포함해 총 개수가 n이라면 리턴
    if(count == n-1) { answer++; return;}

    queen(y,x,1);
    //다음 열에 대해 재귀호출
    for(int i = 0; i<n; i++){
        bf(i, x+1 ,count+1);
    }
    queen(y,x,-1);
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) bf(i,0,0);
    cout<<answer;

}