#include<bits/stdc++.h>
using namespace std;

vector<int> input;
bool check[101];
int n, k, answer;

int func(int idx){
    //아이디어 : 꽂아진 플러그 중, 
    //1. 앞으로 나오지 않거나 2. 가장 늦게 사용하는 플러그를 찾는다.
    //처음에 앞으로의 사용 횟수가 적은 플러그로 생각해 헤맸다.
    vector<int> temp(k+1);
    int ret = 0, temp1 = 0;
    for(int i=idx; i<input.size();i++){
        //꽂아진 플러그 중, 처음 나왔으면 인덱스를 기록한다.
        if(check[input[i]]&& temp[input[i]]==0) 
            temp[input[i]] = i;
    }
    for(int i=1; i<=k; i++)
        //1. 꽂아졌지만 앞으로 나오지 않을 경우
        if(check[i]&&temp[i]==0) return i;
        //2. 가장 늦게 나오는 플러그
        else if(check[i]&& temp[i]>0 && temp[i]>temp1){
            temp1 = temp[i]; ret = i;
        }
    return ret;
}
int main(){
    cin>>n>>k;
    int x; cin>>x; input.push_back(x);
    //연속된 숫자 정리
    for(int i=1;i<k;i++){
        int x; cin>>x;
        if(input[input.size()-1]!=x) input.push_back(x);
    }
   
    int temp = 0, idx = 0;
    for( idx=0; idx<input.size();idx++){
        //플러그가 이미 꽂아져 있을 경우는 패스한다
        if(check[input[idx]]==false){
            //구멍이 다 찼을 땐 뺄 플러그를 찾는다 
            if(temp == n) {
                int temp1 = func(idx);
                check[input[idx]] = true; check[temp1] = false;
                answer++;
            }
            //구멍이 남았을 땐 그냥 꽂는다
            else {
                check[input[idx]]=true; temp++;
            }
        }
    }
    cout<<answer;
}