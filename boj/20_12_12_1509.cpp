#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
string s;
int cache[2501];
int check[2501][2501];

//s[start]~s[end]가 팰린드롬인지 검사한다
bool pal(int start, int end){
    //기저 조건
    if(start>=end) return true;

    //부분 문제 메모이제이션
    int& ret = check[start][end];
    if(ret!=-1 ) return ret;

    //팰린드롬이 아닐 때
    if(s[start]!=s[end]) return ret=false;

    //다음 재귀 호출
    return ret=pal(start+1,end-1);
}
int main(){
    cin>>s; s = '#'+ s;
    memset(check,-1,sizeof(check));
    //초기항
    cache[0]=0;

    //점화식 : cache[i] = 0~i번째 문자열까지 팰린드롬 문자열 최소 개수
    //         j~i범위 문자열 검사 후 팰린드롬이면 min(cache[j-1]+1)
    for (int i = 1; i < s.size(); i++) {
        cache[i] = cache[i - 1] + 1;
        for (int j = 1; j < i; j++){
            if (pal(j, i))
                cache[i] = min(cache[i], cache[j - 1] + 1);
        }
    }
    cout<<cache[s.size()-1];
}