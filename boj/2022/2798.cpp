//
// Created by Kim So Hee on 2022/06/28.
//
#include  <bits/stdc++.h>

using namespace std;
int card[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int N, M;
    cin >> N >> M;
    int answer = 0;

    for (int i = 0; i < N; ++i) {
        cin >> card[i];
    }

    for (int i = 0; i < N - 2; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            for (int k = j + 1; k < N; ++k) {
                int sum = card[i] + card[j] + card[k];
                if (sum > M) continue;
                answer = max(answer, sum);

            }
        }
    }
    cout << answer;
}