#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,k,answer;
int input[10];
int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>input[i];
    for(int i=n-1; i>=0; i--){
        answer += k/input[i]; k%=input[i];
    }
    cout<<answer;
}