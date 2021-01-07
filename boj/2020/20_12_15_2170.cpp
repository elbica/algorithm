#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n; cin>>n;
    vector<pair<int,int>> input(n);

    for(int i=0;i<n;i++) {
        int x,y; cin>>x>>y;
        if(x > y) swap(x,y);
        input[i]={x,y};
    }

    sort(input.begin(),input.end());
    int bound = input[0].first, upper = input[0].second;
    int answer = 0;
    for(auto i : input){
        int x = i.first, y = i.second;
        if(x > upper){
            answer+=upper-bound;
            upper = y; bound = x;
        }
        else{
            //주의 : y가 항상 upper보다 크다는 보장은 없다
            upper = max(upper, y);
        }
    }
    answer += upper - bound;
    cout << answer << '\n';
}