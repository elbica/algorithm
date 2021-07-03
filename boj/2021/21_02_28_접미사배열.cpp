#include<bits/stdc++.h>
using namespace std;

int main(){
    set<string> s;
    string input; cin>>input;
    for(int i=0; i<input.size(); i++){
        s.insert(input.substr(i));
    }
    for(auto p = s.begin(); p!=s.end(); p++){
        cout<<*p<<'\n';
    }

}