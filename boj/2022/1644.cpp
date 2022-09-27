//
// Created by Kim So Hee on 2022/09/27.
//

#include <bits/stdc++.h>

#define MAX 4000000

using namespace std;
vector<int> prime;
bool notPrime[MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        if (!notPrime[i]) prime.push_back(i);
        for (int j = i; j <= n; j += i) {
            notPrime[j] = true;
        }
    }
    /**
     * 연속된 수 합 - two pointer
     * start = 0, end = 0, sum
     * sum <= n, end++;
     * sum > n, start++;
     */
    if (n == 1) {
        cout << 0;
        return 0;
    }

    int start = 0, end = 0, sum = prime[0], answer = 0, size = prime.size();
    while (end < size && prime[end] <= n && start <= end) {
        if (sum == n) answer++;
        if (sum <= n) {
            end++;
            sum += prime[end];
        } else {
            sum -= prime[start];
            start++;
        }
    }

    cout << answer;

}