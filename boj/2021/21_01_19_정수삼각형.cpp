#include<bits/stdc++.h>
using namespace std;

int n;
int input[500][500];
int cache[500][500];

int dp(int i, int j){
    //기저 : 삼각형 맨 밑에 도달했을 때
    if(i == n-1) return input[i][j];
    
    int& ret = cache[i][j];
    if(ret != -1 ) return ret;

    //점화식 : 현재 위치 값 + dp(왼쪽 대각선 or 오른쪽 대각선)
    ret = max(dp(i+1,j) + input[i][j] , dp(i+1,j+1) + input[i][j]);
    return ret;

}
int main(){
    memset(cache,-1,sizeof(cache));
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++) cin>>input[i][j];
    
    cout<<dp(0,0);

}