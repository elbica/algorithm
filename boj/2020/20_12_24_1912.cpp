#include<bits/stdc++.h>
using namespace std;

int n;
int input[100000];
int cache[100000][2];

int main(){
    cin>>n;
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    for(int i=0;i<n;i++) cin>>input[i];

    //초기 항
    cache[0][0] = -9999;
    cache[0][1] = input[0];

    //1. cache[i][0] : 0 ~ i-1번째 수 까지 연속된 수의 최대 합(i-1번째 제외)
    //2. cache[i][1] : 0 ~ i-1번째 수 까지 연속된 수의 최대 합(i-1번째 포함)
    for(int i=1;i<n;i++){
        cache[i][0] = max(cache[i-1][0],cache[i-1][1]);

        //2. 1연속 부터 다시 시작, 또는 계속 연속
        cache[i][1] = max(input[i],cache[i-1][1]+input[i]);
    }
    cout<<max(cache[n-1][0],cache[n-1][1]);
}