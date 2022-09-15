//
// Created by Kim So Hee on 2022/09/15.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1);

    for (int i = 0; i < m; ++i) {
        int s;
        cin >> s;
        int parent;
        cin >> parent;
        for (int j = 0; j < s - 1; ++j) {
            int singer;
            cin >> singer;
            graph[parent].push_back(singer);
            indegree[singer]++;
            parent = singer;
        }
    }

    vector<int> answer;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int here = q.front();
        q.pop();
        answer.push_back(here);
        for (const auto &child: graph[here]) {

            indegree[child]--;
            if (indegree[child] == 0) q.push(child);

        }
    }
    if (answer.size() < n) cout << 0;
    else
        for (const auto &a: answer) {
            cout << a << '\n';
        }

}