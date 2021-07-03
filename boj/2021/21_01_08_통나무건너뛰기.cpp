#include<bits/stdc++.h>
using namespace std;

int main(){
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    int T; cin>>T;
    //정규분포 모양 형태로 숫자들을 배열한다
    while(T--){
        int n; cin>>n;
        vector<int> input(n), result;
        queue<int> q; stack<int> s;
        for(int i=0;i<n;i++) cin>>input[i];
        sort(input.begin(),input.end());
        
        for(int i=0;i<input.size();i++){
            if(i%2==0) q.push(input[i]);
            else s.push(input[i]);
        }

        while(!q.empty()){
            result.push_back(q.front()); q.pop();
        }
        while(!s.empty()){
            result.push_back(s.top()); s.pop();
        }
        int temp = 0;
        for(int i=0;i<result.size()-1;i++){
            if(abs(result[i]-result[i+1])>temp)
                temp = abs(result[i]-result[i+1]);
        }
        cout<<temp<<'\n';
    }
}