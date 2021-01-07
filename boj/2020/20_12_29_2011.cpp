#include<bits/stdc++.h>
#define MOD 1000000
using namespace std;

int arr[5001];
int cache[5001];
bool check(int i, int j){
    //2개로 자른 숫자가 0으로 시작하면 안된다
    if(j==0) return false;

    int num = 10*j + i;
    if(num>=1 && num<=26) return true;
    return false;
}
int main(){
    string s; cin>>s;
    //예외 처리 1 : 입력이 0일 때
    if(s[0]=='0') {cout<<0; return 0;}

    //초기 항
    cache[0] = cache[1] = 1;
    for(int i=1; i<=s.size(); i++) arr[i] = s[i-1]-'0';
    for(int i=2; i<=s.size(); i++){
        //숫자를 1 또는 2개를 뽑아 올바른 범위 안에 있으면 cache를 더한다
        if(arr[i] != 0) cache[i] += (cache[i-1]) % MOD;
        if(check(arr[i],arr[i-1])) cache[i] += (cache[i-2]) % MOD;

        //예외 처리 2 : 0이 연속될 때
        if(arr[i]+arr[i-1]==0){ cout<<0; return 0;}
        cache[i]%=MOD;
    }
    cout<<cache[s.size()];
}
