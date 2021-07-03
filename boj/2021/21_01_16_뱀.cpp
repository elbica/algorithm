#include<bits/stdc++.h>
using namespace std;

int N, K, L;
int arr[101][101]; //1 : 사과, 2 : 뱀의 몸
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int idx = 0; //뱀의 방향

int main(){
//뱀 : (0,0)에서 시작. 초기 길이 1. 초기 방향 오른 쪽. 초마다 이동
    cin>>N>>K;
    for(int i=0; i<K; i++){
        int x, y; cin>>x>>y;
        arr[x][y] = 1;
    }
    queue<pair<int,int>> q; q.push({1,1}); //뱀의 경로 저장 : 큐 사용
    int start = 1, starty = 1, startx = 1, count = 0, answer = 0, time;
    cin>>L;
    for(int i=0; i<L; i++){
        char direc; cin>>time>>direc;
        for(start; start <= time; start++){
            starty += dy[idx]; startx += dx[idx];
            //1. 벗어났거나 부딪힌 경우
            if(starty < 1 || startx < 1 || starty > N || startx > N ||
                arr[starty][startx] == 2) {
                    cout<<start; return 0;
                }
             q.push({starty,startx}); //머리의 경로 저장

            //2. 사과가 없을 경우 경로 중 꼬리를 pop 한다      
            if(arr[starty][startx]==0) {
                auto p = q.front();
                arr[p.first][p.second] = 0; //뱀 제거
                q.pop();
            }
            arr[starty][startx] = 2; //뱀 표시
        }
        if(direc=='L') idx = (idx+1) % 4;
        else idx = (idx+3) % 4;
    }
    //3. 같은 방향으로 전진
    answer = time;
    while(true){
        answer++;
        starty += dy[idx]; startx += dx[idx];

        if(starty < 1 || startx < 1 || starty > N || startx > N || arr[starty][startx]==2) 
             break;
                
        q.push({starty,startx});        
        if(arr[starty][startx] == 0) {
            auto p = q.front();
            arr[p.first][p.second] = 0;
            q.pop();
        }
        arr[starty][startx] = 2; 
    } 
    cout<<answer;
}