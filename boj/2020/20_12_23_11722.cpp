#include<bits/stdc++.h>
using namespace std;

int input[1001];
int cache[1001];
int N;

int dp(int start){
    int& ret = cache[start];
    if(ret != -1 ) return ret;
    ret = 1;

    for(int i=start;i<=N;i++){
        if(input[i] < input[start]) 
            ret = max(ret,dp(i) + 1);
    }
    return ret;
}
int main(){
    cin>>N;
    memset(cache,-1,sizeof(cache));
    input[0] = 9999;
    for(int i = 1 ; i <= N; i++) cin>>input[i];
    cout<<dp(0)-1;
}