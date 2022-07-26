//
// Created by Kim So Hee on 2022/07/26.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin>>n;
    vector<vector<pair<int,int>>> inputs(n+1);

    for (int i = 0; i < n; ++i) {
        int v, e, w; cin>>v>>e>>w;
        inputs[v].push_back({e, w});
        inputs[e].push_back({v, w});
    }

    int source = 1, answer = 0;

    for (int i = 0; i < 2; ++i) {
        queue<int> q; q.push(source);
        vector<int> visited(n+1, -1);
        answer = 0;
        visited[source] = 0;

        while (!q.empty()) {
            int here = q.front(); q.pop();
            for (auto [next, distance] : inputs[here]) {
                if(visited[next] == -1){
                    visited[next] = visited[here]+distance;
                    q.push(next);
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if(answer < visited[j]){
                answer = visited[j];
                source = j;
            }
        }
    }
    cout<<answer;
}