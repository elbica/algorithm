#include<bits/stdc++.h>
using namespace std;

int cache[1001][3], input[1001];
int n;

int dp(int idx, int version){
    //메모이제이션 : [탐색 시작점][증가/감소]
    int& ret = cache[idx][version + 1];
    if(ret != -1 ) return ret;
    
    ret = 0;
    for(int i = idx + 1; i <= n; i++){
        //version = 1 (증가 수열), -1 (감소 수열)
        if(input[idx]*version < input[i]*version){
            ret = max(ret,dp(i,version) + 1);
            //증가 수열을 찾을 때만 감소 수열로 전환 가능
            if(version == 1) 
                ret = max(ret, dp(i, -version) + 1);
        }
    }
    return ret;
}
int main(){
    cin>>n;
    memset(cache,-1,sizeof(cache));
    for(int i=1; i<=n; i++) cin>>input[i];

    cout<<dp(0,1);
}