//
// Created by Kim So Hee on 2022/08/05.
//

#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string input, boom;
    cin >> input >> boom;
    stack<char> solve, temp;

    for (int i = input.length() - 1; i >= 0; i--) {
        temp.push(input[i]);
    }
    int b = 0;
    while (!temp.empty()) {
        /**
         * 1. input[i] == boom[b]
         *   st.push(input[i])
         *   i++, b++;
         *   매칭 완료 시 b만큼 st.pop 후
         *   b개 st --> input으로 이동
         *
         * 2. input[i] != boom[b]
         *   b==0 i++, st.push
         *   b>=1 b개 st --> input으로 이동, i -= (b-1), b = 0
         *
         */
        char here = temp.top();
        temp.pop();
        solve.push(here);
        if (here == boom[b]) {
            b++;
            if (b == boom.length()) {
                for (int i = 0; i < b; ++i) {
                    solve.pop();
                }
                while (!solve.empty() && b--) temp.push(solve.top()), solve.pop();
                b = 0;
            }
        } else {
            while (!solve.empty() && b--) temp.push(solve.top()), solve.pop();
            b = 0;
        }
    }
    if (solve.size() == 0) {
        cout << "FRULA";
        return 0;
    }

    stack<char> answer;
    while (!solve.empty()) answer.push(solve.top()), solve.pop();
    while (!answer.empty()) {
        cout << answer.top();
        answer.pop();
    }
}