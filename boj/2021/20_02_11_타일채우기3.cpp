#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

ll arr[1000001][2];
int main(){
    int n; cin>>n;
    arr[0][0] = 0;
    arr[1][0] = 2;
    arr[2][0] = 7;
    arr[2][1] = 1;
    for(int i=3; i<=n; i++){
        arr[i][1] = (arr[i-1][1] + arr[i-3][0]) % MOD;
        arr[i][0] = (2*arr[i-1][0] + 3*arr[i-2][0] + 2*arr[i][1]) % MOD;
    }
    cout<<arr[n][0];
}