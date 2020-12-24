#include<bits/stdc++.h>
using namespace std;

int cache[300];
int input[300];

int main(){
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>input[i];
    //초기 항
    cache[0] = input[0];
    cache[1] = input[0] + input[1];
    cache[2] = input[2] + (input[1] > input[0]? input[1] : input[0]);
    
    //점화식 : 1. 연속 1개 계단, 2. 연속 2개 계단
    for(int i=3;i<n;i++){
        cache[i] = max(cache[i-2]+input[i] , cache[i-3]+input[i-1]+input[i]);
    }
    cout<<cache[n-1]<<endl;
}