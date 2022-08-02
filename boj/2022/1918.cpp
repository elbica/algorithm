//
// Created by Kim So Hee on 2022/08/01.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<pair<int, char>> oper;
    string input;
    cin >> input;
    string answer;

    /**
     * 문자열을 순회하면서 연산자는 우선 순위와 묶어 stack에 저장한다
     *  +, - : 1
     *  *, / : 2
     *  () : +2, 또는 ( 를 만날 때 까지 pop
     *
     *  현재 연산자 우선 순위 <= stack의 원소를 모두 빼내고, 연산자를 저장한다
     *  문자열 순회가 끝나면 stack에 남은 원소를 모두 빼낸다
     */
    int priority = 0;
    for (const auto &s: input) {
        if (s == '+' || s == '-') {
            int check = 1 + priority;
            while (!oper.empty() && oper.top().first >= check) answer.push_back(oper.top().second), oper.pop();

            oper.push({check, s});
        } else if (s == '*' | s == '/') {
            int check = 2 + priority;
            while (!oper.empty() && oper.top().first >= check) answer.push_back(oper.top().second), oper.pop();

            oper.push({check, s});
        } else if (s == '(') {
            priority += 2;
        } else if (s == ')') {
            priority -= 2;
        } else {
            answer.push_back(s);
        }
    }
    while (!oper.empty()) answer.push_back(oper.top().second), oper.pop();

    cout << answer;
}