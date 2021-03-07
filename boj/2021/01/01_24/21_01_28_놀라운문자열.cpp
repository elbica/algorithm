#include<bits/stdc++.h>
using namespace std;

string s;

void print(){
    for(int i=1; i<s.size(); i++){
        set<string> check;
        for(int j=0; j+i<s.size(); j++){
            string temp="";
            temp.push_back(s[j]), temp.push_back(s[i+j]);
            check.insert(temp);
        }
        if(check.size()!=s.size()-i){cout<<s<<" is NOT surprising."<<endl; return;}

    }
    cout<<s<<" is surprising."<<endl;
        
}
int main(){
    while(true){
        cin>>s;
        if(s=="*") break;
        print();
    }
}