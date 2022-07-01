//
// Created by Kim So Hee on 2022/07/01.
//

#include <bits/stdc++.h>

using namespace std;
int answer[2], N;
int paper[129][129];

bool isFill(int y, int x, int length) {
    int start = paper[y][x];
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; ++j) {
            if (start != paper[i + y][j + x])
                return false;
        }
    }
    return true;
}

void devide(int y, int x, int length) {
    if (isFill(y, x, length)) {
        answer[paper[y][x]]++;
    } else {
        devide(y, x, length / 2);
        devide(y, x + length / 2, length / 2);
        devide(y + length / 2, x, length / 2);
        devide(y + length / 2, x + length / 2, length / 2);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> paper[i][j];
        }
    }

    devide(0, 0, N);

    cout << answer[0] << ' ' << answer[1];

}