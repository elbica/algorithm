//
// Created by Kim So Hee on 2022/07/12.
//

#include <bits/stdc++.h>

using namespace std;
int n, answer;

int visited[16][16];

void backTracking(int column, int number) {

    if (column == n - 1) {
        answer++;
        return;
    }
    for (int i = column + 1; i < n; i++) {
        visited[number][i]++;
        if (number - (i - column) >= 0) visited[number - (i - column)][i]++;
        if (number + (i - column) < n) visited[number + (i - column)][i]++;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i][column + 1]) backTracking(column + 1, i);
    }
    for (int i = column + 1; i < n; i++) {
        visited[number][i]--;
        if (number - (i - column) >= 0) visited[number - (i - column)][i]--;
        if (number + (i - column) < n) visited[number + (i - column)][i]--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        backTracking(0, i);
    }
    cout << answer;
}