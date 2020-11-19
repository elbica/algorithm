#include<iostream>
#define INF 1000010000
using namespace std;

int input[101][101];
int n, m;
int main() {
	cin.tie(NULL); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	//INF로 배열 초기화
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			input[i][j] = INF;
		
	for (int i = 0; i < m; i++) {
		int x, y, c; cin >> x >> y >> c;
		//중복된 버스 노선이 있을 수 있다
		if (c < input[x][y]) input[x][y] = c;
	}

	//플로이드 와샬 알고리즘
	//k : 거쳐가는 도시, i : 시작 도시, j : 도착 도시
	//거쳐가는 비용과 바로 가는 비용과 비교
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