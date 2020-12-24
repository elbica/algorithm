#include<bits/stdc++.h>
#define INF 987654321
using namespace std;

int N;
vector<int> precal;
int cache[100001];
int dp(int x){
    //기저 조건
    if(x==1) return 1;
    else if(x==0) return 0;

    int& ret = cache[x];
    if(ret != -1 ) return ret;

    ret = INF;
    //점화식
    for(int i = precal.size()-1; i>=0; i--){
        if(precal[i] <= x){
            ret = min(ret, dp(x - precal[i]) + 1);
        }
    }
    return ret;
}
int main(){
    cin>>N;
    memset(cache,-1,sizeof(cache));
    for(int i=1; i*i<=100000; i++)
        precal.push_back(i*i);
    
    cout<<dp(N);
}