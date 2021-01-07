#include<bits/stdc++.h>
using namespace std;

int cache[31];
int dp(int x){
    //기저 조건
    if(x==0) return 1;
    else if(x==2) return 3;

    //메모이제이션
    int& ret = cache[x];
    if(ret!=-1 )return ret;

    ret=0;
    //점화식 : 길이가 2일 경우만 경우의 수 3, 나머지 경우 2
    for(int i=2; i<=x; i+=2){
        if(i==2) ret+= 3*dp(x-i);
        else ret+=2*dp(x-i);
    }
    return ret;
}
int main(){
    int N; cin>>N;
    memset(cache,-1,sizeof(cache));
    cout<<dp(N);
}