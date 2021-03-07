#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        int result[4]={};
        for(auto c : s){
            if(c>='a'&&c<='z') result[0]++;
            else if(c>='A'&&c<='Z') result[1]++;
            else if(c>='0'&&c<='9') result[2]++;
            else if(c==' ') result[3]++;
        }
        for(int i=0; i<4; i++) cout<<result[i]<<' ';
        cout<<'\n';
    }
}