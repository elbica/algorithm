#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

void cal(int start, vector<int>& costs, vector<vector<pair<int,int>>>& graph){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, start}); // (cost, here)
    costs[start] = 0;
    
    while(!pq.empty()){
        auto [total, here] = pq.top(); pq.pop();
        for(auto [cost, next] : graph[here]){
            if(total + cost >= costs[next]) continue;
            costs[next] = total + cost;
            pq.push({total + cost, next});
        }
    }

}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<pair<int,int>>> graph(n+1);
    for(auto f : fares){
        int start = f[0], end = f[1], cost=f[2];
        graph[start].push_back({cost, end});
        graph[end].push_back({cost, start});
    }
    
    vector<int> init(n+1, 987654321);
    int answer = 987654321;
    
    cal(s, init, graph);
    for(int i=1; i<=n; i++){
        if(init[i] == 987654321) continue;
        vector<int> next(n+1, 987654321);
        cal(i, next , graph );
        
        answer = min(answer, init[i] + next[a] + next[b]);
        // cout<<init[i]<<' '<<next[a]<<' '<<next[b]<<' '<< answer<<endl;
    }
    
    return answer;
}