//
// Created by Kim So Hee on 2022/06/30.
//

#include <bits/stdc++.h>

using namespace std;
int N, r, c;

int visited = -1;

/**
 *
 * @param y1
 * @param x1
 * @param y2
 * @param x2
 * @details
 *   (y, x, 길이) 로 인자 3개를 받는게 더 간편하다.
 */
void Z(int y1, int x1, int y2, int x2) {
    if (r < y1 || r > y2 || c < x1 || c > x2) {
        visited += (y2 - y1 + 1) * (x2 - x1 + 1);
        return;
    }

    if (y1 == y2 && x1 == x2) {
        visited++;
        if (y1 == r && x1 == c) cout << visited;
        return;
    }
    int midY = (y1 + y2 + 1) / 2;
    int midX = (x1 + x2 + 1) / 2;
    Z(y1, x1, midY - 1, midX - 1);
    Z(y1, midX, midY - 1, x2);
    Z(midY, x1, y2, midX - 1);
    Z(midY, midX, y2, x2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> r >> c;
    Z(0, 0, (1 << N) - 1, (1 << N) - 1);
}