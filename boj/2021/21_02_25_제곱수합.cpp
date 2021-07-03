#include<bits/stdc++.h>
using namespace std;

int n; 
int nemo[333];
int dp[100001];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) dp[i] = 987654321;
    
    dp[0] = 0;
    for(int i=1; i<=320; i++) nemo[i] = i*i;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=316; j++){
            if(i-nemo[j]<0) continue;
            dp[i] = min(dp[i],dp[i-nemo[j]]+1);
        }
    }
    
    cout<<dp[n];
}

