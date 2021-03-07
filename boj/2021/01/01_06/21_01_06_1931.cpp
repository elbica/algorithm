#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i].second >> input[i].first;
    //끝나는 시간 기준으로 오름차순 정렬
    sort(input.begin(), input.end());

    ll start = 0, end = 0;
    int answer = 0;
    //끝나는 시간이 빠른 회의부터 탐색한다.
    for (int i = 0; i < n; i++)
    {
        if (input[i].second >= end)
        {
            end = input[i].first;
            start = input[i].second;
            answer++;
        }
    }

    cout << answer;
}