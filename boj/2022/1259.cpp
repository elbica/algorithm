//
// Created by Kim So Hee on 2022/06/28.
//
#include <bits/stdc++.h>
using namespace std;

string isPalindrom(string s){

    for (int i = 0; i < s.length()/2; ++i) {
        if(s[i] != s[s.length()-i-1]) return "no";
    }
    return "yes";
}

int main(){
    while(1){
        string n; cin>>n;
        if(n=="0") break;
        cout<< isPalindrom(n)<<'\n';
    }
}