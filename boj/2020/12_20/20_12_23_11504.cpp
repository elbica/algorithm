#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll N,M,X,Y;
ll input[102];

bool check(int idx, int m){
    ll num = 0;
    for(int i=m;i>0;i--){
        num += ceil(input[idx]*pow(10,i-1));
        idx = (idx+1) % N;
    }
    if(num>= X && num<=Y) return true;
    return false;
}
int main(){
    int T; cin>>T;
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);

    while(T--){
        cin>>N>>M; X = Y = 0;
        
        for(int j=M; j>0; j--){
            int z; cin>>z;
             X+= ceil(z*pow(10,j-1));
        }
        for(int j=M; j>0; j--){
            int z; cin>>z;
             Y += ceil(z*pow(10,j-1)); 
        }
        for(int i=0;i<N;i++) cin>>input[i];
        
        ll Count = 0;
        for(int i=0;i<N;i++){
            if(check(i,M)) Count++;
        }
        cout<<Count<<'\n';
    }
}