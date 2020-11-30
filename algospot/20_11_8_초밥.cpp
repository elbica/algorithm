#include<iostream>
#include<algorithm>
using namespace std;

int n, m, price[20], pref[20];
int c[201];

int sushi() {
	int ret = 0;
	c[0] = 0; //�ʱ� ��
	for (int b = 1; b <= m; b++) {
		int cand = 0;
		//���� ���� b������ ��ȣ�� �ִ� �� =
		// max(���� b-dish������ ��ȣ�� �� + dish�� ��ȣ��)
		for (int dish = 0; dish < n; dish++) {
			if (b >= price[dish])
				cand = max(cand, c[(b - price[dish]) % 201] + pref[dish]);
		}
		//price�� �ִ� 200�̹Ƿ� 
		//c�迭�� �ִ� �� �ε����� 200 ������ �����Ѵ�
		//���� �迭 ũ��� 201�� ������ �ȴ�
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