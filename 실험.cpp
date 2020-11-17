#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

const int MAX_N = 16;
int k;
string word[MAX_N];
int cache[MAX_N][1 << MAX_N], overlap[MAX_N][MAX_N];
int restore(int last, int used) {
	if (used == (1 << k) - 1) return 0;

	int& ret = cache[last][used];
	if (ret != -1) return ret;
	ret = 0;
	for(int next=0;next<k;next++)
		if ((used&(1 << next)) == 0) {
			int cand = overlap[last][next] + restore(next, used + (1 << next));
			ret = max(ret, cand);
		}
	return ret;
}
string reconstruct(int last, int used) {
	if (used == (1 << k) - 1) return "";

	for (int next = 0; next < k; next++) {
		if (used&(1 << next)) continue;

		int ifused = restore(next, used + (1 << next)) + overlap[last][next];
		if (restore(last, used) == ifused)
			return (word[next].substr(overlap[last][next]) +
				reconstruct(next, used + (1 << next)));
	}
	return "**";
}

int pre() {
	int ret = 0;
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			if (i == j)
				continue;
			// https://chosh95.tistory.com/33
			const string &s1 = word[i];
			const string &s2 = word[j];
			for (int len = min(s1.size(), s2.size()); len > 0; len--)
			{
				if (s1.substr(s1.size() - len) == s2.substr(0, len))
				{
					overlap[i][j] = len;
					break;
				}
			}

			int len = s2.size();
			for (int pos = 0; pos + len <= s1.size(); ++pos)
			{
				if (s1.substr(pos, len) == s2)
				{
					ret |= (1 << j);
					break;
				}
			}
		}
	}

	return ret;
}
int main() {
	int C; cin >> C;
	while (C--) {
		memset(cache, -1, sizeof(cache));
		memset(overlap, 0, sizeof(overlap));
		cin >> k;
		for (int i = 0; i < k; i++) cin >> word[i];
		int visit = pre();
		/*
		int check = 0;
		int start = 0;

		for (int i = 0; i < k; i++) {
			int c = restore(i, visit);
			if (check < c) { start = i; check = c; }
		}*/
		word[k] = "";
		restore(k, visit);
		string a = reconstruct(k, visit);
		cout << a << endl;
	}
}