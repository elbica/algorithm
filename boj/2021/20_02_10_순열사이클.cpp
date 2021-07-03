#include<bits/stdc++.h>
using namespace std;

bool check[1001];
int input[1001];

int main(){
    int T; cin>>T;
    while(T--){
        memset(check,false,sizeof(check));
        memset(input,0,sizeof(input));
        int n; cin>>n;
        for(int i=1; i<=n; i++) cin>>input[i];
        int count = 0;
        for(int i=1; i<=n; i++){
            if(check[i]) continue;
            int here = i;

            while(!check[here]){
                check[here] = true;
                here = input[here];
            }
            count++; 
        }
        cout<<count<<endl;
    }
}