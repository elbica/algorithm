#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[2001];
long long cache[2001][2001];
int prefix[2001];

long long dp(int start, int end){
    if (start == end)  return arr[start];

    long long &ret = cache[start][end];
    if (ret != -1)  return ret;

    //1. start를 먼저 수확하는 경우
    //2. end를 먼저 수확하는 경우
    ret = max(ret, dp(start + 1, end) + (prefix[end] - prefix[start]) + arr[start]);
    ret = max(ret, dp(start, end - 1) + (prefix[end - 1] - prefix[start - 1]) + arr[end]);
    return ret;
}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    memset(cache,-1,sizeof(cache));
    int n; cin >> n;

    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) prefix[i] = prefix[i-1]+arr[i];

/*  탐욕법 기반 코드인데 왜 안될까...??
    끝점과 시작점 중 가치가 작은 벼를 먼저 수확한다..
    int count=0; long long answer=0;
    while(count++!=n){
        if(arr[startidx]>arr[endidx]){
            answer+=arr[endidx]*count;
            endidx--;
        }
        else{
            answer+=arr[startidx]*count;
            startidx++;
        }
    }*/
    cout<<dp(1,n)<<'\n';
    
}