#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int Empty = -987654321;
int n, board[50];
int cache[50][50];
int play(int left, int right) {
	if (left > right) return 0;
	int& ret = cache[left][right];
	if (ret != Empty) return ret;

	ret = max(board[left] - play(left + 1, right),
		board[right] - play(left, right - 1));
	if (right - left + 1 >= 2) {
		ret = max(ret, -play(left + 2, right));
		ret = max(ret, -play(left, right - 2));
	}
	return ret;
}
int main() {
	int C; cin >> C;
	while (C--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> board[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) cache[i][j] = Empty;
		cout << play(0, n - 1) << endl;
	}
}