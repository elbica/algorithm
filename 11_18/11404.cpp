#include<iostream>
#define INF 1000010000
using namespace std;

int input[101][101];
int n, m;
int main() {
	cin.tie(NULL); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	//INF�� �迭 �ʱ�ȭ
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			input[i][j] = INF;
		
	for (int i = 0; i < m; i++) {
		int x, y, c; cin >> x >> y >> c;
		//�ߺ��� ���� �뼱�� ���� �� �ִ�
		if (c < input[x][y]) input[x][y] = c;
	}

	//�÷��̵� �ͼ� �˰���
	//k : ���İ��� ����, i : ���� ����, j : ���� ����
	//���İ��� ���� �ٷ� ���� ���� ��
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (input[i][k] + input[k][j] < input[i][j])
					input[i][j] = input[i][k] + input[k][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i==j || input[i][j] == INF) cout << 0 << ' ';
			else cout << input[i][j] << ' ';
		}
		cout << '\n';
	}
}