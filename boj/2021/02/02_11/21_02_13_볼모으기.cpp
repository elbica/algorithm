#include<bits/stdc++.h>
using namespace std;

int n;
char input[555555];

int main(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>input[i];
    char start = input[n-1];
    int checkidx = -1;
    for(int i = n-2; i>=0; i--){
        if(input[i]!=start){
            checkidx = i; break;
        }
    }
    int red = 0, blue = 0;
    for(; checkidx>=0; checkidx--){
        if(input[checkidx]=='R') red++;
        else blue++;
    }

    char start1 = input[0];
    int checkidx1 = -1;
    for(int i = 0; i<n; i++){
        if(input[i]!=start1){
            checkidx1 = i; break;
        }
    }
    int red1 = 0, blue1 = 0;
    for(; checkidx1<n; checkidx1++){
        if(input[checkidx1]=='R') red1++;
        else blue1++;
    }

    cout<<min(min(red,blue),min(red1,blue1));
}