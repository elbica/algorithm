#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int l[5000], m[5000], g[5000]; //�Ÿ�, ���� �� ����, ���� 

//dist �������� k�� �̻��� ǥ������ �ִ°�?
bool decision(int dist) {
	int ret = 0; //dist ������ ǥ���� ����

	// l - m : ǥ���� ���� ��ġ
	// ǥ���� ���� ��ġ�� dist���� ���� ǥ���ǵ鸸 ����Ѵ�
	for (int i = 0; i < n; i++) {
		if (dist >= l[i] - m[i])
			ret += (min(dist, l[i]) - (l[i] - m[i])) / g[i] + 1;
	}
	return ret >= k;
}
int optimize() {
	int lo = -1, hi = 8030000;
	while (lo + 1 < hi) { //���̰� 1�� ���� ����
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