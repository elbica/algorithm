#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int, int>> input; //점수,인덱스
vector<vector<int>> arr;
bool dudu[100000001];
ll answer;
int n;

int main()
{
    cin >> n;
    input.resize(n * n);
    arr.resize(n * n);
    for (int i = 0; i < n * n; i++)
    {
        int score, temp;
        cin >> score >> temp;
        input[i].first = score;
        input[i].second = i;
        for (int j = 0; j < temp; j++)
        {
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
    }
    sort(input.rbegin(), input.rend());
    for (auto i : input)
    {
        int hereidx = i.second;
        int score = i.first;
        for (auto j : arr[hereidx])
        {
            if (dudu[j])
                continue;
            dudu[j] = true;
            answer += score;
        }
    }
    cout << answer;
}