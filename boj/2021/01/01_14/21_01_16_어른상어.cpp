#include<bits/stdc++.h>
using namespace std;

int n,m,k,Count,answer;
int arr[20][20], smells[20][20];
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,-1,1,0,0};
//상어 1이 가장 강력. N * N. M 칸에 상어.
//각각의 상어는 자신의 위치에 냄새를 뿌림. 
//냄새는 상어가 k번 이동하면 사라짐
//초마다 상하좌우 중 하나 이동. 냄새 뿌림. 아무 냄새 없는 칸 -> 자신 냄새 방향
//우선순위는 상어마다 다름. 같은 상어라도 현재 방향에 따라 다름. 
//종료 : 한칸에 여러마리? 가장 작은 번호 상어 제외 쫓겨남
//1 위, 2 아래, 3 왼쪽, 4 오른쪽
struct shark{
    bool disappear = false;
    int num, direction, y, x, nexty, nextx, nextd;
    int priority[5][4];
    queue<pair<int,int>> q;
    shark(int n, int Y, int X) : num(n), y(Y), x(X) {
        for(int i=0; i<k-1; i++) q.push({-1,-1});
    }
    shark(){}
    void prev(){
        if(disappear){ smell(); return; }
        direction = nextd; //방향 갱신
        q.push({y,x}); arr[y][x] = -num; smells[y][x]++; //냄새 변경
        smell(); 
        y = nexty; x = nextx;
        if(check(y,x)) { //자신보다 낮은 번호의 상어가 이미 있는 경우
            disappear = true; Count--;
        }
        else //정상적인 경우 이동을 확정.  
            arr[y][x] = num;
    }
    void move(){
        if(disappear) return; 
        nextd = direc();
        nexty = y + dy[nextd]; nextx = x + dx[nextd];
    }
    int direc(){
        for(int i=0; i<4; i++){ //빈칸이 있는 경우
            int nextDirect = priority[direction][i];
            int nextY = y + dy[nextDirect], nextX = x + dx[nextDirect];
            if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) continue;
            if(!arr[nextY][nextX]) return priority[direction][i];
        }
        for(int i=0; i<4; i++){ //자기 냄새 방향
            int nextDirect = priority[direction][i];
            int nextY = y + dy[nextDirect], nextX = x + dx[nextDirect];
            if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) continue;
            if(arr[nextY][nextX] == -num) return priority[direction][i];
        }
    }
    bool check(int y, int x){
        //냄새 제외, 이동할 위치에 다른 상어가 있을 때
        if(arr[y][x] > 0 && arr[y][x] < num) return true;
        return false;
    }
    void smell(){
        //냄새 삭제
        if(q.size() > 0){
            int removeY = q.front().first, removeX = q.front().second;
            q.pop();
            if(removeY != -1 && removeX != -1) {
                smells[removeY][removeX]--;
                if(!smells[removeY][removeX]) arr[removeY][removeX] = 0;
            }
        }
    }
};

int main(){
    cin >> n >> m >> k; Count = m;
    vector<shark> sharks(m+1);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j] != 0)  sharks[arr[i][j]] = shark(arr[i][j], i, j);
        }
    for(int i=1; i<=m; i++) cin>>sharks[i].direction;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=4; j++)
            for(int k=0; k<4; k++) cin>>sharks[i].priority[j][k];
    }
    while(true){
        //미리 이동할 좌표를 탐색한 후, 한꺼번에 이동한다
        for(int i=1; i<sharks.size(); i++) sharks[i].move(); 
        for(int i=1; i<sharks.size(); i++) sharks[i].prev();     
        answer++;

        if(Count<=1) break;
        if(answer > 1000) { cout<<-1; return 0; }
    }
    cout<<answer;
}