#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[101];

int main(){
    arr[1]=arr[2]=arr[3]=1;
    arr[4]=arr[5]=2;
    for(int i=6; i<=100; i++)
        arr[i] = arr[i-5]+arr[i-1];
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        cout<<arr[n]<<endl;
    }
}