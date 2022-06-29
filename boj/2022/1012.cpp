//
// Created by Kim So Hee on 2022/06/29.
//

#include <bits/stdc++.h>

using namespace std;
/*
 * @details
 *   input, check 굳이 2개 배열을 만들지 않아도
 *   방문하면 input 배열 엘리먼트를 false 처리 해도 된다
 *
 * */
int input[51][51];
bool check[51][51];
int answer = 0;
int M, N, K;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

/**
 *
 * @param x
 * @param y
 * @details
 *   queue를 사용한 while 문 구현 방법도 있다
 */

void bfs(int x, int y) {
    if (input[y][x] == 0 || check[y][x]) return;
    check[y][x] = true;

    for (int i = 0; i < 4; ++i) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
        bfs(nextX, nextY);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        memset(input, 0, sizeof(input));
        memset(check, 0, sizeof(check));
        answer = 0;
        cin >> M >> N >> K;
        while (K--) {
            int X, Y;
            cin >> X >> Y;
            input[Y][X] = true;

        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (input[i][j] == 0 || check[i][j]) continue;
                bfs(j, i);
                answer++;
            }
        }
        cout << answer << '\n';
    }

}