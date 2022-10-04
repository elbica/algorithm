//
// Created by Kim So Hee on 2022/10/03.
//

#include <bits/stdc++.h>

using namespace std;

int uni[100001], answer;

int find(int x) {
    if (uni[x] == x) return x;
    return uni[x] = find(uni[x]);
}

void merge(int l, int s) {
    uni[find(l)] = find(s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int g, p;
    cin >> g >> p;
    /**
     * 그리디
     * g, g-1, g-2 순으로 탐색
     *  - 최대한 높은 게이트부터 도킹
     *  - 매 탐색마다 게이트를 for로 찾을려면 시간초과
     *  - 유니온 파인드로 경로 압축 가능 (uni[gate] = max_gate)
     *
     */
    for (int i = 1; i <= g; ++i) uni[i] = i;

    for (int i = 0; i < p; ++i) {
        int num;
        cin >> num;
        int gate = find(num);
        if (gate == 0) break;

        answer++;
        merge(gate, gate - 1);
    }
    cout << answer;
}