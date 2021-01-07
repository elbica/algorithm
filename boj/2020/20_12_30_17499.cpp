#include<bits/stdc++.h>
using namespace std;

int input[200000];
int idx;
int main(){
    int n,q; cin>>n>>q;
    for(int i=0;i<n;i++) cin>>input[i];
    for(int i=0;i<q;i++){
        int v; cin>>v;
        if(v==1){
            int j,x; cin>>j>>x;
            input[(j-1+idx)%n]+=x;
        }
        else if(v==2){
            int x; cin>>x;
            idx = (idx-x+n) % n;
        }
        else {
            int x; cin>>x;
            idx = (idx+x) % n;
        }
    }
    int count = 0, i = idx;
    while(count<n){
        count++;
        cout<<input[i]<<' ';
        i = (i+1)%n;
    }
}