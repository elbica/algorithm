#include<bits/stdc++.h>
using namespace std;

int arr[222];
int main(){
    string s; cin>>s;
    for(auto c : s)
        arr[c]++;
    for(char c = 'a'; c<='z'; c++) cout<<arr[c] <<' ';
    
}