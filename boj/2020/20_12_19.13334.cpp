#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    int n; cin>>n;
    vector<pair<int,int>> input(n);

    //도착점 기준으로 오름차 순 정렬한다.
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        if(x<y) swap(x,y);
        input[i]={x,y};
    }
    sort(input.begin(),input.end());
    int d; cin>>d;

    //도착점-d > 시작점이라면 무시
    //작다면 "도착점-d ~ 시작점" 구간을 만들어서 부분 합 처리한다.
    //도착점-d 에는 1 부여, 시작점+1 에는 -1을 부여한다
    vector<pair<int,int>> result;
    for(auto& c: input){
        if(c.first-d > c.second) continue;
        result.push_back({c.first-d,1});
        result.push_back({c.second+1,-1});
    }

    //각 점들을 오름차순 정렬하여 부여된 값들을 차례로 더해나간다
    sort(result.begin(),result.end());
    int Count=0, answer = 0;
    for (auto& c : result){
        Count+=c.second;
        if(Count>answer) answer= Count;
    }
    cout<<answer<<endl;

}