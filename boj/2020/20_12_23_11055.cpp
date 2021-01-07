#include<bits/stdc++.h>
using namespace std;

int input[1001];
int cache[1001];
int N;

int dp(int start){
    int& ret = cache[start];
    if(ret != -1 ) return ret;
    ret = input[start];

    for(int i=start;i<=N;i++){
        if(input[i]>input[start]) 
            ret = max(ret,dp(i)+input[start]);
    }
    return ret;
}
int main(){
    cin>>N;
    memset(cache,-1,sizeof(cache));
    for(int i=1;i<=N;i++) cin>>input[i];
    cout<<dp(0);
}