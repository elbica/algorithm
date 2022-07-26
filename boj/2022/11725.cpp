//
// Created by Kim So Hee on 2022/07/25.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1);
    vector<int> answer(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (const auto &child: graph[here]) {
            if (!visited[child]) {
                visited[child] = true;
                answer[child] = here;
                q.push(child);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << answer[i] << '\n';
    }

}