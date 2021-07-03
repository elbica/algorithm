#include<bits/stdc++.h>
using namespace std;

int main(){
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    int n,k; cin>>n>>k;
    vector<int> input(n);
    for(int i=0 ;i<n; i++) cin>>input[i];
    sort(input.begin(),input.end());
    cout<<input[k-1];
}