#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    vector<pair<int,int>> input;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        input.push_back({x,-1});
        input.push_back({y,1});
    }
    //아이디어 : 입력을 정렬시키고 1과 -1 짝을 맞춰나간다.
    //마지막 짝을 맞췄을 때(스택이 비었을 때) 그 둘의 번호 차를 더해준다
    sort(input.begin(),input.end());
    stack<int> s;
    int answer=0;
    for(auto i : input){
        if(i.second==-1) s.push(i.first);
        else{
            int temp = s.top(); s.pop();
            if(s.size()==0){
                answer+=i.first-temp;
            }
        }
    }
    cout<<n-answer<<endl;
}