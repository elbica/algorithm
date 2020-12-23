#include<bits/stdc++.h>
using namespace std;

int input[1000];
int cache[1000];
int N;

int dp(int start){
    int& ret = cache[start];
    if(ret != -1 )return ret;
    ret = 1;
    for(int i=start;i<N;i++){
        if(input[i]>input[start]) 
            ret = max(ret,dp(i)+1);
    }
    return ret;
}
int main(){
    cin>>N;
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<N;i++) cin>>input[i];
    int answer = 0;
    for(int i=0;i<N;i++) answer = max(answer,dp(i));
    cout<<answer;
}