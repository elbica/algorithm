//
// Created by Kim So Hee on 2022/08/04.
//

#include <bits/stdc++.h>

using namespace std;

int N, M;
int inputs[8], answer[8];

void bt(int idx, int depth) {
    if (depth == M) {
        for (int i = 0; i < M; ++i) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = idx; i < N; ++i) {
        answer[depth] = inputs[i];
        bt(i, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> inputs[i];
    }
    sort(inputs, inputs + N);
    bt(0, 0);

}