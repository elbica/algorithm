//
// Created by Kim So Hee on 2022/07/03.
//

#include <bits/stdc++.h>

using namespace std;

/**
 * 좌표 압축
 *   큰 범위의 좌표를 정렬 하여 다시 순서를 부여 한다
 *   중간에 비어있는 빈칸을 없애는 것이 좌표압축의 목표이다!
 *
 *   1. std::map 사용
 *   2. binary search, unique 사용
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    vector<int> output(input);
    sort(output.begin(), output.end());
    output.erase(unique(output.begin(), output.end()), output.end());

    for (const auto &in: input) {
        auto iterator = lower_bound(output.begin(), output.end(), in);
        cout << iterator - output.begin() << ' ';
    }
}