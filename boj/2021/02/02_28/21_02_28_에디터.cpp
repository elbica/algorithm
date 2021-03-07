#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<char> s1, s2;
    string s; cin>>s;
    for(auto c : s) s1.push(c);
    int m; cin>>m;
    for(int i=0; i<m; i++){
        char v,temp; cin>>v;
    
        if(v=='L'){
            if(!s1.empty()){
                temp = s1.top(); s1.pop(), s2.push(temp);
            }
            
        }
        else if(v=='D'){
            if(!s2.empty()){
                temp = s2.top(); s2.pop(),s1.push(temp);
            }
        }
        else if(v=='B'){
            if(!s1.empty()) s1.pop();
        }
        else if(v=='P'){
            char x; cin>>x;
            s1.push(x);
        }
        
    }
    string temp1="",temp2="";
    while(!s1.empty()){
        temp1.push_back(s1.top()), s1.pop();
    }
    while(!s2.empty()){
        temp2.push_back(s2.top()), s2.pop();
    }
    for(int idx = temp1.size()-1; idx>=0; idx--) cout<<temp1[idx];
    for(int idx = 0; idx<temp2.size(); idx++) cout<<temp2[idx];

}