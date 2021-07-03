#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n; 
    while(n--){
        stack<char> s;
        string input; cin>>input;
        for(auto i : input){
            if(i=='(') s.push(i);
            else{
                if(s.empty()){ cout<<"NO"<<'\n'; goto next;}
                else s.pop();
            }
        }
        if(!s.empty()) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
        next: continue;
    }
}