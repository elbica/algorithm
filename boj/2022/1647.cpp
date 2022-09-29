//
// Created by Kim So Hee on 2022/09/27.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    vector<bool> visited(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    int answer = 0, maxCost = 0;

    for (int i = 0; i < n; i++) {
        while (!pq.empty()) {
            auto [cost, here] = pq.top();
            pq.pop();
            if (visited[here]) continue;
            visited[here] = true;
            for (const auto [next, distance]: graph[here]) {
                pq.push({distance, next});
            }
            answer += cost;
            maxCost = max(maxCost, cost);
        }
    }
    cout << answer - maxCost;

}