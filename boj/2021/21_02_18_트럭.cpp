#include <bits/stdc++.h>
using namespace std;

int n, w, L, input[1000];

int main()
{
    cout.tie(0);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> w >> L;
    for (int i = 0; i < n; i++)
        cin >> input[i];
    queue<int> q;
    for (int i = 0; i < w; i++)
        q.push(0);

    int in = 0, idx = 0, time = 0;
    while (true)
    {
        if (idx >= n)
            break;
        in -= q.front();
        q.pop();
        time++;
        if (input[idx] + in > L)
        {
            q.push(0);
        }
        else
        {
            q.push(input[idx]);
            in += input[idx++];
        }
    }
    cout << time + w;
}