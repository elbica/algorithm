//
// Created by Kim So Hee on 2022/07/27.
//

#include <bits/stdc++.h>

using namespace std;

bool inputs[1001][1001];
bool visited[1001][1001][2];

int dy[4]{-1, 0, 1, 0};
int dx[4]{0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            inputs[i][j] = c - '0';
        }
    }
    int distance = 0;
    queue<tuple<int, int, bool>> q;
    q.push({0, 0, false});
    visited[0][0][0] = true;

    while (!q.empty()) {
        auto size = q.size();
        distance++;
        for (int i = 0; i < size; ++i) {
            const auto [y, x, broken] = q.front();
            q.pop();
            if (y == n - 1 && x == m - 1) {
                cout << distance;
                return 0;
            }
            for (int j = 0; j < 4; ++j) {
                int nextY = y + dy[j], nextX = x + dx[j];

                if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;

                // 이미 벽을 부순 경우
                if (broken) {
                    if (!inputs[nextY][nextX] && !visited[nextY][nextX][true]) {
                        visited[nextY][nextX][true] = true;
                        q.push({nextY, nextX, true});
                    }
                } else {
                    if (inputs[nextY][nextX] && !visited[nextY][nextX][true]) {
                        visited[nextY][nextX][true] = true;
                        q.push({nextY, nextX, true});
                    }
                    if (!inputs[nextY][nextX] && !visited[nextY][nextX][false]) {
                        visited[nextY][nextX][false] = true;
                        q.push({nextY, nextX, false});
                    }
                }

            }
        }
    }
    cout << -1;
}