//
// Created by Kim So Hee on 2022/06/30.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<>> pq;

    while (N--) {
        int number;
        cin >> number;
        if (number == 0) {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            } else cout << 0 << '\n';
        } else pq.push(number);
    }
}