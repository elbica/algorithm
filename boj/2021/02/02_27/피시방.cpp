/*
[2번 문제]import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p, n, h;
    cin >> p >> n >> h;
    vector<vector<int>> input;
    vector<int> result(p + 1);
    input.resize(p + 1);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        input[x].push_back(y);
    }
    for (int i = 1; i <= p; i++)
    {
        sort(input[i].begin(), input[i].end());
    }
    for (int i = 1; i <= p; i++)
    {
        int temp = h;
        int sum = 0;
        for (auto time : input[i])
        {
            if (temp - time >= 0)
            {
                sum += time * 1000;
                temp -= time;
            }
        }
        result[i] = sum;
    }

    for (int i = 1; i <= p; i++)
    {
        sort(input[i].rbegin(), input[i].rend());
    }
    for (int i = 1; i <= p; i++)
    {
        int temp = h;
        int sum = 0;
        for (auto time : input[i])
        {
            if (temp - time >= 0)
            {
                sum += time * 1000;
                temp -= time;
            }
        }
        result[i] = max(result[i], sum);
    }
    for (int i = 1; i <= p; i++)
    {
        cout << i << ' ' << result[i] << '\n';
    }
}