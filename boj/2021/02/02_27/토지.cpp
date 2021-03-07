#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll grand[1111];
ll prefix[1111];
ll cache[1025][1025];
int n;

ll recur(int start, int end)
{
    cout<<start<<' '<<end<<endl;
    if (start == end)
    {
        return 0;
    }
    //memoiz
    ll& ret = cache[start][end];
    if(ret!=-1) {cout<<"memo"<<endl; return ret;}
    int mid = (start + end) / 2;
    //start~mid mid+1~end;

    ll temp1 = 0;
    ll temp2 = 0;
    for (int i = start; i <= mid; i++)
    {
        temp1 = max(temp1, grand[i]);
    }
    for (int i = mid + 1; i <= end; i++)
        temp2 = max(temp2, grand[i]);
  
        ll temp3 = temp1 + recur(mid + 1, end);
        temp3 = max(temp3, temp2 + recur(start, mid));
        return ret = temp3;
    
}
int main()
{

    cin >> n;
    memset(cache,-1,sizeof(cache));
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        grand[i] = x;
        prefix[i] = prefix[i - 1] + x;
    }
    cout << recur(1, n);
}