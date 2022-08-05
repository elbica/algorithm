//
// Created by Kim So Hee on 2022/08/05.
//

#include <bits/stdc++.h>

using namespace std;

int N, M;
int inputs[9][9], temp[9][9];
bool visited[9][9];
vector<pair<int, int>> virus, plain;
int answer = 0;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
    if (visited[y][x]) return;

    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty()) {
        auto [hereY, hereX] = q.front();
        q.pop();
        if (temp[hereY][hereX] == 0) temp[hereY][hereX] = 2;

        for (int i = 0; i < 4; ++i) {
            int nextY = hereY + dy[i], nextX = hereX + dx[i];

            if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M) continue;
            if (visited[nextY][nextX]) continue;
            visited[nextY][nextX] = true;

            if (temp[nextY][nextX] != 1)
                q.push({nextY, nextX});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> inputs[i][j];
            if (inputs[i][j] == 2) virus.emplace_back(i, j);
            else if (inputs[i][j] == 0) plain.emplace_back(i, j);
        }
    }
    /**
     * 1. 벽 3개 세우기
     * 2. 바이러스 3개 전파
     * 3. 0인 칸 개수 세기
     * 4. 반복
     */
    for (int i = 0; i < plain.size(); ++i) {
        for (int j = i + 1; j < plain.size(); ++j) {
            for (int k = j + 1; k < plain.size(); ++k) {
                memcpy(temp, inputs, sizeof(inputs));

                temp[plain[i].first][plain[i].second] = 1;
                temp[plain[j].first][plain[j].second] = 1;
                temp[plain[k].first][plain[k].second] = 1;

                memset(visited, 0, sizeof(visited));
                for (const auto &v: virus) {
                    bfs(v.first, v.second);
                }

                int empty = 0;
                for (int l = 0; l < N; ++l) {
                    for (int m = 0; m < M; ++m) {
                        if (temp[l][m] == 0) empty++;
                    }
                }
                answer = max(answer, empty);
            }
        }
    }
    cout << answer;
}