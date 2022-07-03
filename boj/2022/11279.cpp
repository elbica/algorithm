//
// Created by Kim So Hee on 2022/07/01.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    priority_queue<int> pq;
    int N;
    cin >> N;
    while (N--) {
        int x;
        cin >> x;
        if (x != 0) {
            pq.push(x);
        } else if (!pq.empty()) {
            cout << pq.top() << '\n';
            pq.pop();
        } else cout << 0 << '\n';
    }

}