#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Time;
int N;
bool bs(unsigned long long x)
{
    unsigned long long n = N;
    for (auto t : Time)
    {
        n -= x / t;
        if (n <= 0)
            return true;
    }
    return false;
}
long long solution(int n, vector<int> times)
{
    long long answer = 0;
    Time = times;
    N = n;
    sort(Time.begin(), Time.end());
    unsigned long long start = 0, end = 18446744073709551615;
    while (start < end)
    {
        unsigned long long mid = (start + end) / 2;
        if (bs(mid))
        {
            end = mid - 1;
        }
        else
            start = mid;
    }
    return start;
}