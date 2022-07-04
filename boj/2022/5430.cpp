//
// Created by Kim So Hee on 2022/07/04.
//

#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

/**
 *  vector 대신에 deque를 썼으면
 *  start, end 가리키는 인덱스 변수 없어도 된다
 */

int main() {
    ios::sync_with_stdio(false);

    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s, x;
        cin >> s;
        int n;
        cin >> n;
        cin >> x;
        auto inputs = split(x.substr(1, x.length() - 2), ',');
        bool reverse = false, error = false;
        int start = 0, end = inputs.size() - 1;

        for (const auto &command: s) {
            if (command == 'R') {
                reverse = !reverse;
            } else if (command == 'D') {
                if (start > end) error = true;
                if (reverse) end--;
                else if (!reverse) start++;

            }
        }
        if (error) cout << "error" << '\n';
        else {
            cout << '[';
            if (reverse && start <= end) {
                for (int i = end; i > start; --i) {
                    cout << inputs[i] << ',';
                }
                cout << inputs[start];

            } else if (start <= end) {
                for (int i = start; i < end; ++i) {
                    cout << inputs[i] << ',';
                }
                cout << inputs[end];
            }
            cout << "]\n";
        }
    }

}