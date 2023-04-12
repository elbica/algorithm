#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int visited[10'001];
vector<string> answer;

void bt(vector<vector<string>> tickets, vector<string> path, string cur){
    if(path.size() == tickets.size()){
        // 모두 방문
        path.push_back(cur);
        if(answer.size()==0) answer = path;
        return;
    }
    for(int i=0; i<tickets.size(); i++){
        if(visited[i]) continue;
        string start = tickets[i][0], end = tickets[i][1];
        if(start != cur) continue;
        
        path.push_back(start);
        visited[i] = true;
        bt(tickets, path, end);
        visited[i] = false;
        path.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    bt(tickets, {}, "ICN");
    return answer;
}