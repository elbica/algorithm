//
// Created by Kim So Hee on 2022/07/01.
//

#include <bits/stdc++.h>

using namespace std;

int network[101][101];
int visited[101];
int answer = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    int x;
    cin >> x;
    for (int i = 0; i < x; ++i) {
        int left, right;
        cin >> left >> right;
        network[left][right] = network[right][left] = 1;
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        if (visited[here]) continue;
        visited[here] = true;
        answer++;
        for (int i = 1; i < 101; ++i) {
            if (network[here][i])
                q.push(i);
        }
    }
    cout << answer;
}