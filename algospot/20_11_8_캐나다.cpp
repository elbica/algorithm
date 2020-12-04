#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int l[5000], m[5000], g[5000]; //거리, 시작 전 미터, 간격 

//dist 지점까지 k개 이상의 표지판이 있는가?
bool decision(int dist) {
	int ret = 0; //dist 까지의 표지판 개수

	// l - m : 표지판 시작 위치
	// 표지판 시작 위치가 dist보다 작은 표지판들만 계산한다
	for (int i = 0; i < n; i++) {
		if (dist >= l[i] - m[i])
			ret += (min(dist, l[i]) - (l[i] - m[i])) / g[i] + 1;
	}
	return ret >= k;
}
int optimize() {
	int lo = -1, hi = 8030000;
	while (lo + 1 < hi) { //차이가 1이 나면 종료
		int mid = (lo + hi) / 2;
		if (decision(mid)) hi = mid;
		else lo = mid;
	}
	return hi;
}
int main() {
	int T; cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> l[i] >> m[i] >> g[i];
		cout << optimize() << endl;
	}
}