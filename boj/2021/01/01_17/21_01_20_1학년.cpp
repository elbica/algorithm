#include<bits/stdc++.h>
#define ll long long
using namespace std;

//cache[n][i] : i번째 인덱스까지 n을 만들 수 있는 경우의 수
ll cache[21][101];
ll input[101], n;

int main(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>input[i];
    cache[input[0]][0] = 1;

    //bottom up
    //n-2 인덱스 까지, 1~20 을 만들 수 있는 경우의 수를 각각 구하고
    //input[n-1]에 해당하는 수를 출력하면 된다
    for(int i=1; i<n-1; i++){
        int here = input[i];
        for(int j=0; j+here <= 20; j++)
            cache[j+here][i] += cache[j][i-1];
        
        for(int j=20; j-here >= 0; j--)
             cache[j-here][i] += cache[j][i-1];
    }
    cout<<cache[input[n-1]][n-2];
}