#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<pair<int,int>> input(routes.size());
    for(int i=0; i<routes.size();i++){
        input[i].second = routes[i][0];
        input[i].first = routes[i][1];
    }
    sort(input.begin(),input.end());
    int endCheck = -33333;
    for(auto& i : input){
        if(endCheck < i.second){
            answer++; endCheck = i.first;
        }
    }
    return answer;
}