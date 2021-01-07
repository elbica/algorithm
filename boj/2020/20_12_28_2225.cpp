#include<bits/stdc++.h>
#define MOD 1000000000
#define ll long long
using namespace std;
ll arr[201][201];
int main(){
    //초기항 설정
    for(int i=1; i<=200; i++) arr[1][i] = i;
    for(int i=1; i<=200; i++) arr[i][1] = 1;
    for(int i=1; i<=200; i++) arr[0][i] = 1;

    //점화식 : arr[i][j] = i를 정수 j개의 합으로 표현
    // = arr[0][j-1] + arr[1][j-1] + ... + arr[i][j-1]
    for(int i=2; i<=200; i++)
        for(int j=2; j<=200; j++){
            for(int k=0; k<=i; k++){
                arr[i][j] += (arr[k][j-1])%MOD;
                arr[i][j] %= MOD;
            }
        }
    int N,K; cin>>N>>K;
    cout<<arr[N][K]<<endl;

}