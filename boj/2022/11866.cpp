//
// Created by Kim So Hee on 2022/06/29.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, K;
    cin >> N >> K;
    queue<int> que;
    for (int i = 0; i < N; ++i) {
        que.push(i + 1);
    }
    cout << '<';
    while (que.size() != 1) {
        for (int i = 0; i < K - 1; ++i) {
            int temp = que.front();
            que.pop();
            que.push(temp);
        }
        cout << que.front() << ", ";
        que.pop();
    }
    cout << que.front() << '>';
}