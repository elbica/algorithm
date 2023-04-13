#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> up[101],down[101];

int bfs(vector<int> graph[], int start){
    bool visited[101] = {};
    queue<int> q; q.push(start);
    visited[start] = true;
    int count = 0;
    
    while(!q.empty()){
        int here = q.front(); q.pop();
        for(auto next : graph[here]){
            if(visited[next]) continue;
            visited[next] = true;
            count++;
            q.push(next);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> results) {
    for(auto r : results){
        int win=r[0], fail=r[1];
        up[win].push_back(fail);
        down[fail].push_back(win);
    }
    
    int answer = 0;
    
    for(int i=1; i<=n; i++){
        if(bfs(up, i) + bfs(down, i) + 1 == n) answer++;
    }
    
    return answer;
}