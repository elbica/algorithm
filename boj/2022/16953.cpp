//
// Created by Kim So Hee on 2022/08/04.
//

#include <bits/stdc++.h>

#define MAX 1'000'000'000

using namespace std;

set<int> cache;
int a, b;
bool flag;

void bfs(int number, int depth) {
    if (cache.count(number)) return;
    cache.insert(number);

    if (number == b) {
        flag = true;
        cout << depth + 1;
        return;
    }

    if (number * 2 <= MAX) {
        bfs(number * 2, depth + 1);

    }
    if ((long long) 10 * number + 1 <= MAX) {
        bfs(number * 10 + 1, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> b;
    bfs(a, 0);
    if (!flag) cout << -1;
}