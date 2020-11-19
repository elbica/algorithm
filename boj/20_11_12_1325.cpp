#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N, M;
vector<vector<int>> adj;
int check;
vector<int> answer;

void bfs(int start) {
	queue<int> q;
	vector<bool> visited(N + 1);
	q.push(start);
	visited[start] = true;

	int Count = 0;
	while (!q.empty()) {
		Count++;
		int here = q.front(); q.pop();
		for(auto c: adj[here])
			if (!visited[c]) {
				visited[c] = true;
				q.push(c);
			}
	}
	if (Count > check) {
		check = Count;
		answer.clear(); answer.push_back(start);
	}
	else if (Count == check) {
		answer.push_back(start);
	}
}

int main() {
	cin.tie(NULL); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	adj.resize(N + 1);
	//visited.assign(N + 1, vector<bool>(N + 1));

	for (int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;
		adj[y].push_back(x);
	}
	for (int i = 1; i <= N; i++) bfs(i);
	for (auto c : answer) cout << c << ' ';
	cout << endl;
}