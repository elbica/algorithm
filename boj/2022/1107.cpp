
//
// Created by Kim So Hee on 2022/07/03.
//

#include <bits/stdc++.h>

#define MAX 987654321

using namespace std;

int N, length;
int answer = MAX, M;
vector<bool> error(10);

/**
 *
 * @param number 누른 채널
 * @param depth 누른 횟수
 * 자릿수 변경 때문에 헤맸다..
 * 100번 입력 --> 99번 등으로 자릿수가 바뀔 수도 있다
 */
void permutation(int number, int depth) {
    if(depth) {
        if (length == depth || length - 1 == depth) {
            answer = min(answer, depth + abs(N - number));
        }
        if (length + 1 == depth || depth == 6) {
            answer = min(answer, depth + abs(N - number));
            return;
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (!error[i])
            permutation(number * 10 + i, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    length = to_string(N).length();
    answer = abs(N - 100);

    for (int i = 0; i < M; ++i) {
        int button;
        cin >> button;
        error[button] = true;
    }
    permutation(0, 0);
    cout << answer;
}