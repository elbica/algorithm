#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int,int>> input;
int main(){
    cin>>n;
    input.resize(n);
    for(int i=0;i<n;i++)
        cin>>input[i].first>>input[i].second;
    
    sort(input.begin(),input.end());
    int r; cin>>r;
    for(int i=0;i<r;i++){
        int l; cin>>l;
        vector<int> answer;
        bool flag=0;
        for(int j=0;j<l;j++){
            int x; cin>>x;
            for(auto c : input){
                if(c.first> x) {flag=1; break;}
                else if(c.first==x) 
                    {answer.push_back(c.second); break;}
            }
        }
        if(flag) cout<<"YOU DIED";
        else {
            for(auto c : answer) cout<<c<<' ';
        }
        cout<<'\n';
    }
}