#include<iostream>
#include<vector>
using namespace std;

int N, answer, blue, white;
vector<vector<int>> arr;

bool check(int fr, int fc, int sr, int sc) {
	int ch = arr[fr][fc];

	for(int i=fr;i<sr;i++)
		for (int j = fc; j < sc; j++) 
			if (arr[i][j] != ch) return false;

	if (ch) blue++;
	else white++;

	return true;//true이면 색 모두 일치
}
void recur(int fr, int fc, int sr, int sc) {
	if (!check(fr, fc, sr, sc)) {
		int newr = (fr + sr) / 2, newc = (fc + sc) / 2;

		recur(fr, fc, newr, newc);
		recur(fr, newc, newr, sc);
		recur(newr, fc, sr, newc);
		recur(newr, newc, sr, sc);
	}
}
int main() {
	cin >> N;
	arr.assign(N, vector<int>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> arr[i][j];

	recur(0, 0, N, N);
	cout << white << endl;
	cout << blue << endl;
}