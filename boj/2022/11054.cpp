//
// Created by Kim So Hee on 2022/08/04.
//

#include <bits/stdc++.h>

using namespace std;

int N, asc[1002], des[1002], inputs[1002], answer = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> inputs[i];
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (inputs[i] > inputs[j]) asc[i] = max(asc[i], asc[j] + 1);
        }
    }

    for (int i = N; i >= 1; i--) {
        for (int j = N + 1; j > i; j--) {
            if (inputs[i] > inputs[j]) des[i] = max(des[i], des[j] + 1);
        }
    }
    for (int i = 1; i <= N; ++i) {
        int check = inputs[i];
        int temp = 0;
        for (int j = i + 1; j <= N; ++j) {
            if (inputs[j] < check) temp = max(temp, des[j]);
        }
        answer = max(answer, asc[i] + temp);
    }

    cout << answer;
}