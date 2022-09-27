//
// Created by Kim So Hee on 2022/09/27.
//

#include <bits/stdc++.h>

using namespace std;

int n, m;
int inputs[21][21];
int answer;
int d[4] = {0, -1, 0, 1};
bool visited[30];


void recur(int y, int x, int depth) {
    /**
     * backtracking
     * 0. depth max 처리
     * 1. 주변 4칸 순회 (방문 안 한 칸만)
     * 2. 주변 칸 방문 처리
     * 3. 재귀
     * 4. 주변 칸 방문 해제
     */
    answer = max(depth, answer);

    for (int i = 0; i < 4; ++i) {
        int nextY = y + d[i], nextX = x + d[(i + 3) % 4];
        if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;
        if (visited[inputs[nextY][nextX]]) continue;
        visited[inputs[nextY][nextX]] = true;

        recur(nextY, nextX, depth + 1);

        visited[inputs[nextY][nextX]] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            inputs[i][j] = c - 'A';
        }
    }

    visited[inputs[0][0]] = true;
    recur(0, 0, 1);

    cout << answer;

}