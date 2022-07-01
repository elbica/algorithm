//
// Created by Kim So Hee on 2022/07/01.
//

#include <bits/stdc++.h>

#define MAX 987654321

using namespace std;

int tomato[1001][1001];
int answer[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill(&answer[0][0], &answer[1000][1001], MAX);

    int M, N;
    cin >> M >> N;
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) q.push({i, j, 0});
            if (tomato[i][j] == -1) answer[i][j] = -1;
        }
    }
    /**
     * queue의 size로 for 문을 돌리면 depth 별로 묶어서 while 문을 진행할 수 있다
     * 굳이 tuple로 depth까지 묶어서 저장할 필요가 없다
     */
    while (!q.empty()) {
        auto here = q.front();
        int hereY = get<0>(here), hereX = get<1>(here), day = get<2>(here);
        q.pop();
        if (hereY < 0 || hereX < 0 || hereY >= N || hereX >= M) continue;
        if (day < answer[hereY][hereX] && tomato[hereY][hereX] != -1) {
            answer[hereY][hereX] = day;
            int nextDay = day + 1;
            q.push({hereY + 1, hereX, nextDay});
            q.push({hereY - 1, hereX, nextDay});
            q.push({hereY, hereX + 1, nextDay});
            q.push({hereY, hereX - 1, nextDay});
        }
    }
    int temp = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            temp = max(temp, answer[i][j]);
        }
    }

    cout << (temp == MAX ? -1 : temp);
}