#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll T, n, m;
vector<ll> inputA, inputB, preA, preB, prefixA, prefixB;
int main()
{
    cin >> T >> n;
    inputA.resize(n);
    for (int i = 0; i < n; i++)
        cin >> inputA[i];
    cin >> m;
    inputB.resize(m);
    for (int i = 0; i < m; i++)
        cin >> inputB[i];

    preA.resize(n + 1), preB.resize(m + 1);
    preA[0] = 0, preB[0] = 0;

    for (int i = 1; i <= n; i++)
        preA[i] = preA[i - 1] + inputA[i - 1];
    for (int i = 1; i <= m; i++)
        preB[i] = preB[i - 1] + inputB[i - 1];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            prefixA.push_back(preA[i] - preA[j]);

    for (int i = 1; i <= m; i++)
        for (int j = 0; j < i; j++)
            prefixB.push_back(preB[i] - preB[j]);

    unordered_map<ll, ll> Count;
    for (auto b : prefixB)
    {
        if (Count.find(b) == Count.end())
            Count[b] = 1;
        else
            Count[b]++;
    }
    sort(prefixA.begin(), prefixA.end());
    ll answer = 0;
    for (auto a : prefixA)
    {
        if (Count.find(T - a) != Count.end())
            answer += Count[T - a];
    }
    cout << answer << endl;
}