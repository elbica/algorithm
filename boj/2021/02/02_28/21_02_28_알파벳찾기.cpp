#include<bits/stdc++.h>
using namespace std;

int arr[222];

int main(){
    memset(arr,-1,sizeof(arr));
    string s; cin>>s;
    for(int i=0; i<s.size(); i++)
        if(arr[s[i]]==-1) arr[s[i]] = i;
    for(char c = 'a'; c<='z'; c++) cout<<arr[c]<<' ';
}