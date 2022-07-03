//
// Created by Kim So Hee on 2022/07/03.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> vec[1001];
int visited[1001];

void dfs(int start) {
    if (visited[start]) return;
    visited[start] = true;
    for (const auto &next: vec[start]) {
        dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i);
            answer++;
        }
    }
    cout << answer;
}