//
// Created by Kim So Hee on 2022/06/29.
//

#include <bits/stdc++.h>

using namespace std;

string isVPS(const string& input){
    stack<bool> st;
    for (auto item: input) {
        if(item == '(') st.push(true);
        else if (st.empty()) return "NO";
        else st.pop();
    }
    return !st.empty() ? "NO" : "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>>T;
    while(T--){
        string s; cin>>s;
        cout<< isVPS(s)<<'\n';
    }

}