#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (minq.size() == 0 && maxq.size() == 0)
        {
            minq.push(x);
            cout << x << '\n';
            continue;
        }
        int minqTop = minq.top();

        if (x >= minqTop)
        {
            minq.push(x);
        }
        else
        {
            maxq.push(x);
        }

        int cmp = minq.size() - maxq.size();
        if (cmp >= 2)
        {
            maxq.push(minq.top());
            minq.pop();
        }
        else if (-cmp >= 2)
        {
            minq.push(maxq.top());
            maxq.pop();
        }

        if (maxq.size() - minq.size() == 0)
        {

            int result = min(maxq.top(), minq.top());
            cout << result << '\n';
        }
        else if (minq.size() - maxq.size() == 1)
        {
            cout << minq.top() << '\n';
        }
        else if (maxq.size() - minq.size() == 1)
        {
            cout << maxq.top() << '\n';
        }
    }
}