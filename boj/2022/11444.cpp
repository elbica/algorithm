//
// Created by Kim So Hee on 2022/08/02.
//

#include <bits/stdc++.h>

#define DIVISOR 1000000007

using namespace std;

map<long long, long long> cache;

/**
 * 도가뉴의 항등식
 * 짝수 : a2n = an(an+2*an-1)
 * 홀수: a2n-1 = (an)^2+(an-1)^2
 */
long long fibo(long long n) {
    if (n == 1) return 1;
    if (n == 0) return 0;
    if (cache.find(n) != cache.end()) return cache[n];

    if (n % 2) {
        long long next = n / 2 + 1;
        return cache[n] = ((fibo(next) * fibo(next)) % DIVISOR + (fibo(next - 1) * fibo(next - 1)) % DIVISOR) % DIVISOR;
    } else {
        long long next = n / 2;
        return cache[n] = fibo(next) * ((fibo(next) + 2 * fibo(next - 1)) % DIVISOR) % DIVISOR;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long int n;
    cin >> n;
    cout << fibo(n);

}