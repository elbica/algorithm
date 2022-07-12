//
// Created by Kim So Hee on 2022/07/06.
//

#include <bits/stdc++.h>

#define MAX 987654321

using namespace std;

int dx[6]{0, 0, -1, 1, 0, 0};
int dy[6]{-1, 1, 0, 0, 0, 0};
int dz[6]{0, 0, 0, 0, 1, -1};
int M, N, H;
int tomato[101][101][101]; // [z][y][x]
int day[101][101][101];
queue<tuple<int, int, int>> q;

void bfs() {
    int depth = -1;

    while (!q.empty()) {
        auto size = q.size();
        depth++;
        for (int i = 0; i < size; ++i) {
            auto here = q.front();
            q.pop();
            int hereZ = get<0>(here), hereY = get<1>(here), hereX = get<2>(here);

            if (hereZ >= H || hereY >= N || hereX >= M || hereZ < 0 || hereY < 0 || hereX < 0) continue;
            if (tomato[hereZ][hereY][hereX] == -1) continue;
            if (depth < day[hereZ][hereY][hereX]) {
                day[hereZ][hereY][hereX] = depth;

                for (int j = 0; j < 6; ++j) {
                    q.push({hereZ + dz[j], hereY + dy[j], hereX + dx[j]});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill(&day[0][0][0], &day[100][100][101], MAX);

    cin >> M >> N >> H;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == -1) day[i][j][k] = -1;
                if (tomato[i][j][k] == 1) q.push({i, j, k});
            }
        }
    }
    bfs();

    int temp = 0;

    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                temp = max(temp, day[k][i][j]);
            }
        }
    }

    cout << (temp == MAX ? -1 : temp);
}