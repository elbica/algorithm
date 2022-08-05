//
// Created by Kim So Hee on 2022/08/05.
//

#include <bits/stdc++.h>

using namespace std;

set<vector<int>> answer;
int N, M;
vector<int> temp, inputs;

void bt(int idx, int depth) {
    if (depth == M) {
        answer.insert(temp);
        return;
    }
    for (int i = idx; i < N; i++) {
        temp[depth] = inputs[i];
        bt(i, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    temp.resize(M), inputs.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> inputs[i];
    }
    std::sort(inputs.begin(), inputs.end());
    bt(0, 0);
    for (const auto &a: answer) {
        for (const auto &number: a) {
            cout << number << ' ';
        }
        cout << '\n';
    }
}