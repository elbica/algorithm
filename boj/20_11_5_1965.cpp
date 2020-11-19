#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> input;
int cache[1001];
int N;
int lis(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;

	ret = 1;
	for (int i = start + 1; i < N; i++) {
		if (input[start] < input[i])
			ret = max(ret, lis(i) + 1);
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	input.resize(N);

	for (int i = 0; i < N; i++) cin >> input[i];
	int answer = 0;
	lis(0);
	for (int i = 0; i < N; i++) answer = max(answer,cache[i]);
	cout << answer << endl;
}