#include<bits/stdc++.h>
using namespace std;
int N,M;
int Key[4][20][20], Lock[20][20];

bool check(int i1, int j1, int version){
    //검사하는 부분 밖의 자물쇠 부분 검사.
    //그 부분에 0이 있으면 실패한 케이스
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            if(i>=i1 && j>=j1&&i<i1+M && j<j1+M) continue;
            if(Lock[i][j]==0) return false;
        }

        //인덱스 범위 체크 주의
        for(int i=0;i<M;i++){
            int checkN = i+i1;
            if(checkN >= N ) break;
            if(checkN < 0) continue;
            for(int j=0;j<M;j++){
                int checkM = j+j1;
                if (checkM >= N) break;
                if(checkM < 0) continue;
                //둘이 같으면 실패한 케이스
                if(Lock[checkN][checkM]==Key[version][i][j])
                    return false;
            }
        }
 
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    N = lock.size(); M = key.size();
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++) Key[0][i][j] = key[i][j];
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) Lock[i][j] = lock[i][j];
    
    //key의 4가지 회전
    for(int i=1;i<4;i++)
        for(int j=0;j<M;j++)
            for(int k=0;k<M;k++)
                Key[i][k][M-1-j] = Key[i-1][j][k];

    //주의! 검사 범위 좌표 조심
    //검사 시작 점을 (-N,-N)부터 돌려야 한다
    for(int i=-N;i<N;i++)
        for(int j=-N;j<N;j++){
            if(check(i,j,0)) return true;
            else if(check(i,j,1)) return true;
            else if(check(i,j,2)) return true;
            else if(check(i,j,3)) return true;
        }

    return false;
}