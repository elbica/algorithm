//
// Created by Kim So Hee on 2022/07/25.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e;
    cin >> v >> e;
    vector<int> visited(v + 1, 987654321);
    vector<vector<pair<int, int>>> graph(v + 1);
    int k;
    cin >> k;
    for (int i = 0; i < e; ++i) {
        int u, s, w;
        cin >> u >> s >> w;
        graph[u].push_back({s, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, k});
    visited[k] = 0;

    while (!pq.empty()) {
        const auto [distance, here] = pq.top();
        pq.pop();

        for (const auto &[next, weight]: graph[here]) {
            int nextWeight = distance + weight;
            if (visited[next] > nextWeight) {
                visited[next] = nextWeight;
                pq.push({nextWeight, next});
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (visited[i] == 987654321) cout << "INF" << '\n';
        else cout << visited[i] << '\n';
    }
}