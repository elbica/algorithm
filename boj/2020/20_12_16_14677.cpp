#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[4]={1,2,0,0};
int input[1503];
int cache[1503][1503];
int N;
//왼쪽에서 start-1까지, 오른쪽에서 end+1까지 먹었을 때,
//다음 먹을 알약(start, end)은 potion이어야 한다
//먹을 수 있는 알약 정보를 인자로 넘겨주었다
int dp(int start, int end, int potion){
    //기저 조건
	if (start > end) {
        return 0;
	}
    int& ret = cache[start][end];
    if(ret!=-1) return ret;
    int nextP = (potion+1) % 3;
    ret=0;
    //1. end가 potion일 때
    if(input[end]==potion){
        ret = max(ret,dp(start,end-1,nextP)+1);
    }
    //2. start가 potion일 때
    if(input[start]==potion){
        ret = max(ret,dp(start+1,end,nextP)+1);
    }
    return ret;
}
int main(){
    cin>>N;
    memset(cache,-1,sizeof(cache));
   
    for(int i=0;i<3*N;i++){
        char x; cin>>x;
        if(x=='B') input[i]=0;
        else if(x=='L') input[i]=1;
        else input[i]=2;
    }
    
    cout<<dp(0,3*N-1,0)<<endl;
}