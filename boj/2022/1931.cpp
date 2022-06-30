//
// Created by Kim So Hee on 2022/06/30.
//

#include <bits/stdc++.h>

using namespace std;
/**
 * @details
 *   대표적인 그리디 알고리즘 --> 프림, 다익스트라
 *   각 단계에서 최선의 선택을 하자!
 *
 *   1. 탐욕적 선택 속성 : 앞의 선택이 이후의 선택에 영향을 주지 않는다
 *   2. 최적 부분 구조 : 최종 해결 방법은 부분 문제 해결 방법으로 구성된다
 *   위 두가지 조건을 만족시켜야, 최적해를 얻을 수 있다
 *   부분 문제들 간 서로 영향을 주면 안된다!
 *
 *   알고리즘의 정당성을 증명하는 것이 중요하다
 다
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int>> inputs;

    int N;
    cin >> N;
    while (N--) {
        int start, end;
        cin >> start >> end;

        inputs.emplace_back(start, end);
    }
    sort(inputs.begin(), inputs.end());
    int tempEnd = 0;
    int answer = 0;
    /**
     *  가장 빨리 끝나는 회의를 골라야 한다!
     *  회의 시작 시간 기준으로 정렬해서.. if문이 복잡해졌다
     *  정해는 끝나는 시간 기준으로 정렬하는 것이다
 다   */
    for (const auto &input: inputs) {
        if (input.first >= tempEnd) {
            tempEnd = input.second;
            answer++;
        } else {
            if (input.second < tempEnd) {
                tempEnd = input.second;
            };
        }
    }
    cout << answer;

}