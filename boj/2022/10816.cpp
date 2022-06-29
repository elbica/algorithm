//
// Created by Kim So Hee on 2022/06/29.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    auto startI = vec.begin();
    auto endI = vec.end();
    cin >> M;
    for (int i = 0; i < M; ++i) {

        /*
         * @description
         *
         *   1.
         *    std::equal_range 라는 함수로 범위 인덱스를 pair로 묶어서 구할 수 있다
         *    ex) pair<int*, int*> range = equal_range(vec.begin(), vec.end(), number)
         *
         *   2. 중복 set을 활용한다
         *
         *   3.
         *    횟수 저장 배열을 사용한다.
         *    ex) COUNT[카드 숫자] = 횟수 + 1;
         *
         * */
        int number;
        cin >> number;
        int answer = 0;
        auto lowerI = lower_bound(startI, endI, number);
        auto upperI = upper_bound(startI, endI, number);
        if (lowerI != endI) answer = upperI - lowerI;
        cout << answer << ' ';

    }
}