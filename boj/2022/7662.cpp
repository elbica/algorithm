//
// Created by Kim So Hee on 2022/07/01.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        multiset<int> lessSet; // 최소 힙
        int k;
        cin >> k;
        while (k--) {
            char c;
            int n;
            cin >> c >> n;
            /**
             * 주의 : multiset.erase는 한 번에 중복된 원소들을 모두 지워버린다
             * find로 우회하여 iterator를 erase 해야한다
             */
            if (c == 'D' && !lessSet.empty()) {
                if (n == -1) {
                    int minElement = *lessSet.begin();
                    lessSet.erase(lessSet.find(minElement));

                } else if (n == 1) {
                    int maxElement = *lessSet.rbegin();
                    lessSet.erase(lessSet.find(maxElement));
                }

            } else if (c == 'I') {
                lessSet.insert(n);
            }
        }
        if (lessSet.empty()) cout << "EMPTY\n";
        else cout << *lessSet.rbegin() << ' ' << *lessSet.begin() << '\n';
    }

}