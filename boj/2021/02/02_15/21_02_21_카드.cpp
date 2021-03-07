#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    map<ll,int> m;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        ll x; cin>>x;
        if(m.find(x)==m.end()) m[x] = 1;
        else m[x]++;
    }
    ll num,temp = 0;
    for(auto p = m.begin(); p!=m.end(); p++){
        if(p->second > temp) {
            num = p->first;
            temp = p->second;
            }
    }
    cout<<num;

}