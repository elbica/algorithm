#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int n; cin>>n; int idx = 0;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        if(s=="push"){int x; cin>>x; v.push_back(x);}
        else if(s=="front"){
            if(v.size()==idx) cout<<-1<<endl;
            else cout<<v[idx]<<endl;
        }
        else if(s=="back"){
            if(v.size()==idx) cout<<-1<<'\n';
            else cout<<v[v.size()-1]<<'\n';
        }
        else if(s=="size"){
            cout<<v.size()-idx<<'\n';
        }
        else if(s=="empty"){
            if(v.size()==idx) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else if(s=="pop"){
            if(v.size()==idx) cout<<-1<<'\n';
            else{
                cout<<v[idx++]<<'\n';
                
            }
        }
    }

}