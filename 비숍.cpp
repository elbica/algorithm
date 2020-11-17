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
int id[2][8][8]; //id[대각선 종류][y좌표][x좌표] = 대각선 번호
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
	//연결된 정점들 정보 저장
	aMatch = vector<int>(n, -1);
	bMatch = vector<int>(m, -1);
	int size = 0;
	for (int start = 0; start < n; start++) {
		visited = vector<bool>(n, false);
		//연결할 수 있으면 개수 증가
		if (dfs(start)) size++;
	}
	return size;
}
int Bishops() {
	memset(id, -1, sizeof(id));
	int count[2] = { 0,0 };
	//대각선 번호 붙이기
	for(int dir=0;dir<2;dir++)
		for(int y=0;y<board.size();y++)
			for(int x=0;x<board.size();x++)
				//빈칸이고, 아직 번호가 붙여지지 않았을 경우
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
	n = count[0]; //오른쪽 아래방향 대각선 개수
	m = count[1]; //오른쪽 위 방향 대각선 개수

	memset(adj, 0, sizeof(adj));
	for (int y = 0; y < board.size(); y++)
		for (int x = 0; x < board.size(); x++)
			if (board[y][x] == '.')
				//좌표 (y,x)을 공유하는 2개의 대각선(정점)을 연결한다
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