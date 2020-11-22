#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//너무 어렵당....ㅠㅠ
using namespace std;

struct Comparator
{
    const vector<int> &group;
    int t;
    Comparator(const vector<int> &g, int _t) : group(g), t(_t) {}
    bool operator()(int a, int b)
    {
        if (group[a] != group[b])
            return group[a] < group[b];
        return group[a + t] < group[b + t];
    }
};
vector<int> getSuffix(const string &s)
{
    int n = s.size();
    int t = 1;
    vector<int> group(n + 1);
    for (int i = 0; i < n; i++)
        group[i] = s[i];
    group[n] = -1;

    vector<int> perm(n);
    for (int i = 0; i < n; i++)
        perm[i] = i;
    while (t < n)
    {
        Comparator comp(group, t);
        sort(perm.begin(), perm.end(), comp);
        t *= 2;
        if (t >= n)
            break;
        vector<int> newg(n + 1);
        newg[n] = -1;
        newg[perm[0]] = 0;
        for (int i = 1; i < n; i++)
            if (comp(perm[i - 1], perm[i]))
                newg[perm[i]] = newg[perm[i - 1]] + 1;
            else
                newg[perm[i]] = newg[perm[i - 1]];
        group = newg;
    }
    return perm;
}
int commonPre(const string &s, int i, int j)
{
    int k = 0;
    while (i < s.size() && j < s.size() && s[i] == s[j])
    {
        ++i;
        ++j;
        ++k;
    }
    return k;
}
int longest(int k, const string &s)
{
    vector<int> a = getSuffix(s);
    int ret = 0;
    for (int i = 0; i + k <= s.size(); i++)
        ret = max(ret, commonPre(s, a[i], a[i + k - 1]));
    return ret;
}
int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        string s;
        int k;
        cin >> k >> s;
        cout << longest(k, s) << '\n';
    }
}