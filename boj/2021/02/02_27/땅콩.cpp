#include <bits/stdc++.h>
using namespace std;
int n, m, e;
vector<int> input;
int main()
{
    cin >> n >> m >> e;
    input.resize(n);
    int answer = 987654321;
    for (int i = 0; i < n; i++)
        cin >> input[i];
    for (int i = 0; i < n - m - 1; i++)
    {
        int end = i + m - 1;
        int temp = input[end] - input[i];
        if (input[i] > e)
            temp += input[i] - e;
        else if (input[end] < e)
            temp += e - input[end];
        answer = min(answer, temp);
    }
    cout << answer;
}