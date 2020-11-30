#include<iostream>
#include<algorithm>
using namespace std;

int n, m, price[20], pref[20];
int c[201];

int sushi() {
	int ret = 0;
	c[0] = 0; //초기 항
	for (int b = 1; b <= m; b++) {
		int cand = 0;
		//현재 예산 b에서의 선호도 최대 값 =
		// max(예산 b-dish에서의 선호도 값 + dish의 선호도)
		for (int dish = 0; dish < n; dish++) {
			if (b >= price[dish])
				cand = max(cand, c[(b - price[dish]) % 201] + pref[dish]);
		}
		//price는 최대 200이므로 
		//c배열은 최대 한 인덱스의 200 전까지 접근한다
		//따라서 배열 크기는 201만 있으면 된다
		c[b % 201] = cand;
		ret = max(ret, cand);
	}
	return ret;
}
int main() {
	int C; cin >> C;
	while (C--) {
		cin >> n >> m; m /= 100;
		for (int i = 0; i < n; i++) { 
			cin >> price[i] >> pref[i];
			price[i] /= 100;
		}
		cout << sushi() << endl;

	}
}