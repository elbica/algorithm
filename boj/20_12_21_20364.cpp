#include<bits/stdc++.h>
using namespace std;
int N,Q;
bool arr[2000000];

void check(vector<int>& v, int key,int here){
    if(here==0) {
        //정상적인 땅 배정
        if(v.size()==0){
        arr[key] = true; //배정 표시
        cout<<0<<'\n'; 
        return;
        }
        //땅 배정을 못 했을 경우
        else{
            cout<<v[v.size()-1]<<'\n';
            return;
        }
    }
    //배정이 된 땅을 만나면 벡터에 저장
    if(arr[here]) {v.push_back(here);}
    check(v,key,here/2);
}
int main(){
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    cin>>N>>Q;
    for(int i=0;i<Q;i++){
        int x; cin>>x;
        vector<int> trace;
        check(trace,x,x);
    }
}