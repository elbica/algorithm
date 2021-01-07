#include<iostream>
#include<map>
using namespace std;

//메모리 절약을 위해 map으로 메모이제이션
map<long long, long long> cache;
long long N,P,Q;

long long dp(long long start){

   auto temp = cache.find(start);
   if(temp!=cache.end()) return temp->second;

    //long long은 나누기 할 때 int처럼 자동 내림 된다
    long long num1 = start/P, num2 = start/Q;

    //map은 인덱스처럼 접근 가능
    return cache[start] = dp(num1)+dp(num2);
}
int main(){
    cache.insert({0,1});
    cin>>N>>P>>Q;
    cout<<dp(N)<<endl;

}