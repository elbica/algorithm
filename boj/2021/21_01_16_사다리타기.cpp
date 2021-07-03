#include<bits/stdc++.h>
using namespace std;

string s, init= "";
int k, n, check;
char arr[1000][26];
int main(){
    cin>>k>>n>>s;
    for(int i = 1, c = 'A'; i <= k; i++,c++) init += char(c);
 
    for(int i=0; i<n; i++)
        for(int j=0; j<k-1; j++) {
            cin>>arr[i][j];
            if(arr[i][j]=='?') check = i;
        }

    for(int start = 0; start < check; start++)
        for(int i=0; i < k-1; i++){
            if(arr[start][i]=='-') swap(init[i],init[i+1]);
        }
    
    for(int end =  n-1; end > check; end--)
        for(int i=0; i < k-1; i++){
            if(arr[end][i]=='-') swap(s[i],s[i+1]);
        }
    
    string temp = "";
    for(int i=0; i<k-1; i++){
        bool prev = 0, cur = 0, next = 0;
        if(i > 0) prev = (s[i]==init[i-1]);
        cur = (s[i]==init[i]);
        if(i < k-1) next = (s[i]==init[i+1]);

        //사다리가 없는 경우
        if(!prev && !next && !cur){
            string answer = "";
            for(int z=0; z<k-1; z++) answer.push_back('x');
            cout<<answer<<endl; return 0;
        }
        //일반적인 경우
        if(next) temp.push_back('-');
        else temp.push_back('*');
    }
    cout<<temp<<endl;
}