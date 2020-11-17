#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

int n, m;
int adj[64][64];
const int dx[2] = { -1,1 };
const int dy[2] = { 1,1 };
vector<string> board;
int id[2][8][8]; //id[�밢�� ����][y��ǥ][x��ǥ] = �밢�� ��ȣ
vector<int> aMatch, bMatch;
vector<bool> visited;

bool dfs(int a) {
	if (visited[a]) return false;
	visited[a] = true;
	for(int b=0;b<m;b++)
		if(adj[a][b])
			if (bMatch[b] == -1 || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
	return false;
}
int biMatch() {
	//����� ������ ���� ����
	aMatch = vector<int>(n, -1);
	bMatch = vector<int>(m, -1);
	int size = 0;
	for (int start = 0; start < n; start++) {
		visited = vector<bool>(n, false);
		//������ �� ������ ���� ����
		if (dfs(start)) size++;
	}
	return size;
}
int Bishops() {
	memset(id, -1, sizeof(id));
	int count[2] = { 0,0 };
	//�밢�� ��ȣ ���̱�
	for(int dir=0;dir<2;dir++)
		for(int y=0;y<board.size();y++)
			for(int x=0;x<board.size();x++)
				//��ĭ�̰�, ���� ��ȣ�� �ٿ����� �ʾ��� ���
				if (board[y][x] == '.'&&id[dir][y][x] == -1) {
					int cy = y, cx = x;
					while (0 <= cy&&cy < board.size() &&
						0 <= cx&&cx < board.size() &&
						board[cy][cx] == '.') {
						id[dir][cy][cx] = count[dir];
						cy += dy[dir]; cx += dx[dir];
					}
					count[dir]++;
				}
	n = count[0]; //������ �Ʒ����� �밢�� ����
	m = count[1]; //������ �� ���� �밢�� ����

	memset(adj, 0, sizeof(adj));
	for (int y = 0; y < board.size(); y++)
		for (int x = 0; x < board.size(); x++)
			if (board[y][x] == '.')
				//��ǥ (y,x)�� �����ϴ� 2���� �밢��(����)�� �����Ѵ�
				adj[id[0][y][x]][id[1][y][x]] = 1;
	return biMatch();
}
int main() {
	int C; cin >> C;
	while (C--) {
		int N; cin >> N;
		board.resize(N);
		for (int i = 0; i < N; i++) cin >> board[i];
		cout << Bishops() << endl;
	}
}