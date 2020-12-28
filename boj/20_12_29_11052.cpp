#include<bits/stdc++.h>
using namespace std;

int p[1001];
int cache[1001];
int n;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    cache[1] = p[1];
    for(int i=2;i<=n;i++){
        cache[i] = p[i];
        for(int j=1; j<i; j++){
            cache[i] = max(cache[i],cache[i-j]+p[j]);
        }
    }
    cout<<cache[n];
}