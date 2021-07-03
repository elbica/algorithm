#include<bits/stdc++.h>
#define ull long long int
using namespace std;

ull input[20], k, n, temp[20], result[20];
set<int> s;
void func1(){
    ull check=1, start = n-1, idx=0;
    for(int i=n-1; i>=1; i--) check*=i;
    while(k!=0 && start > 0){
        temp[idx++] = k/check; 
        k%=check;
        check/=start--;
    }
    for(int i=0; i<n; i++) {
        auto p = s.begin();
        for(int c = temp[i]; c>0; c--) p++;
        result[i] = *p; s.erase(p);
    }
    for(int i=0; i<n; i++) cout<<result[i]<<' ';

}
void func2(){
    ull check=1, start = n-1, idx=0;
    for(int i=n-1; i>=1; i--) check*=i;
    for(int i=0; i<n; i++){
        if(start==0) break;
        auto p = s.begin(); int c = 0;
        for(; input[i]!=*p; p++) c++;
        s.erase(p); k += c*check;
        check/=start--;
    }
    cout<<++k;
}
int main(){
    
    cin>>n;
    int v; cin>>v;
    for(int i=1; i<=n; i++) s.insert(i);
    if(v==1) {
        cin>>k; k--;
        func1();
    }
    else {
        for(int i=0; i<n; i++) cin>>input[i];
        func2();
    }
}