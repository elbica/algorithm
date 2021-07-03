#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> input(n);
    for(int i=0; i<n; i++) cin>>input[i];
    vector<int> temp = input;
    sort(input.begin(), input.end());
    input.erase(unique(input.begin(),input.end()),input.end());

    unordered_map<int,int> m; // key : input, value : input_idx
    for(int i=0; i<n; i++){
        if(m.find(input[i])==m.end()){
            m[input[i]] = i;
        }
    }
    for(auto t : temp) cout<<m[t]<<' ';
}