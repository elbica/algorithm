#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//탐욕법 : 절댓값이 큰 순서대로 곱하면 된다
vector<int> posi, nega;
int N,answer;

void cal(vector<int>& v){
    //주의점 : 1은 곱하는 것보다 따로 더하는게 더 크다!

    if(v.size()%2==0){
        //벡터 사이즈가 짝수일 때
        for(int i=0;i<v.size();i+=2){
            if(v[i+1]!=1)  answer+= v[i]*v[i+1];
            else answer+=v[i]+v[i+1];
        }
    }
    else{
        //홀수일 때
        for(int i=1;i<v.size();i+=2){
            if(v[i]!=1)answer+= v[i]*v[i-1];
            else answer+=v[i]+v[i-1];
        }
        answer+=v[v.size()-1];
    }
}
int main(){
    cin>>N;
    //양수와 음수를 구분에서 벡터에 담는다
    for(int i=0;i<N;i++){
        int x; cin>>x;
        if(x>0) posi.push_back(x);
        else nega.push_back(x);
    }
    //절댓값 순서대로 내림차순으로 정렬한다
    sort(posi.rbegin(),posi.rend());
    sort(nega.begin(),nega.end());
    cal(nega);
    cal(posi);
    cout<<answer<<endl;


}