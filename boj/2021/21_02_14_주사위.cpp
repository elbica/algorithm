#include <bits/stdc++.h>
using namespace std;

long long ud[2], side[4], n, temp;
long long answer;

int main()
{
    cin >> n;
    //n==1 예외처리
    cin >> side[0] >> side[1] >> ud[0] >> ud[1] >> side[3] >> side[2];

    if (n == 1)
    {
        long long checknum = max(ud[0], ud[1]), sum = ud[0] + ud[1];
        for (int i = 0; i < 4; i++)
        {
            checknum = max(checknum, side[i]);
            sum += side[i];
        }
        cout << sum - checknum;
        return 0;
    }
    long long minnum = 987654321, twonum = 987654321, threenum = 987654321;

    temp = min(ud[0], ud[1]);

    for (int i = 0; i < 4; i++)
        minnum = min(minnum, side[i]);
    minnum = min(minnum, temp);

    for (int i = 0; i < 4; i++)
        twonum = min(twonum, temp + side[i]);
    twonum = min(twonum, side[0] + side[3]);
    for (int i = 0; i < 3; i++)
    {
        threenum = min(threenum, temp + side[i] + side[i + 1]);
        twonum = min(twonum, side[i] + side[i + 1]);
    }
    threenum = min(threenum, temp + side[0] + side[3]);

    answer += 4 * threenum;
    answer += twonum * (8 * n - 12);
    answer += minnum * (5 * n * n - 16 * n + 12);
    cout << answer;
}