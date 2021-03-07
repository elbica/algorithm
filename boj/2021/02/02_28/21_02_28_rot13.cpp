#include<bits/stdc++.h>
using namespace std;

char arr[222];
int main(){
    for(char c = 'a'; c<'a'+13; c++) arr[c] = char(c+13);
    for(char c = 'a'+13; c<='z'; c++) arr[c] = char(c-13);
    for(char c = 'A'; c<'A'+13; c++) arr[c] = char(c+13);
    for(char c = 'A'+13; c<='Z'; c++) arr[c] = char(c-13);

    string s; getline(cin,s);
    for(char c : s){
        if(c>='a'&&c<='z' || c>='A'&&c<='Z') cout<<arr[c];
        else cout<<c; 
    }
}