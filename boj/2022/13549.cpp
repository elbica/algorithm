//
// Created by Kim So Hee on 2022/07/27.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> answer(100001, 987654321);
    queue<pair<int, int>> q;
    q.push({n, 0});
    answer[n] = 0;

    while (!q.empty()) {
        const auto [here, depth] = q.front();
        q.pop();

        if (answer[here] < depth) continue;
        if (here > 0 && answer[here - 1] > depth + 1) {
            answer[here - 1] = depth + 1;
            q.push({here - 1, depth + 1});
        }
        if (here < 100000 && answer[here + 1] > depth + 1) {
            answer[here + 1] = depth + 1;
            q.push({here + 1, depth + 1});
        }
        if (2 * here <= 100000 && answer[2 * here] > depth) {
            answer[2 * here] = depth;
            q.push({2 * here, depth});
        }
    }
    cout << answer[k];
}