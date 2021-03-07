#include <string>
#include <vector>
#include <cstring>
#include<iostream>
#define MOD 10007
using namespace std;

int cache[60001];
int recur(int x)
{
    //기저 조건
    if (x <= 1)  return 1;

    //메모이제이션
    int &ret = cache[x]; 
    if (ret != -1)  return ret;

    //점화식
    return ret = (recur(x - 1) % MOD + (2*recur(x - 2)) % MOD) % MOD;
}
int solution(int n)
{
    int answer = 0;
    memset(cache, -1, sizeof(cache));
    answer = recur(n);
    return answer;
} 
int main(){
    int n; cin>>n;
    cout<<solution(n)<<endl;
}