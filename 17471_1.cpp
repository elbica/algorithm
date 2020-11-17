#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int N, check, answer = 987654321;
vector<vector<int>> adj;
vector<int> input;

bool bfs(int a) {
	vector<bool> visited(11, true);
	int start = 0, Count = 0, temp = 0;
	//cout << "½ÇÇà : ";
	for (int i = 1; i <= N; i++){
		bool check = !bool(a & (1 << i));
		visited[i] = check;
		//cout << check << ' ';
		if (!check) { start = i; temp++; }
	}
	queue<int> q;
	q.push(start); visited[start] = true;
	while (!q.empty()) {
		int here = q.front(); q.pop();
		Count++;
		for (int c : adj[here]) {
			if (!visited[c]) {
				visited[c] = true;
				q.push(c);
			}
		}
	}
	//cout << "start : " << start << " Count :" << Count << " temp : " << temp;
	return temp==Count;
}
void dfs(int nums, int others, int here, int sum, int count) {
	if (count > N / 2) return;

	if (bfs(nums) && bfs(others)) {
		answer = min(answer, abs(2 * sum - check));
	}
	/*
	for (int i = 1; i <=N; i++) cout << bool(nums & (1 << i)) << ' ';
	cout <<"bfs : "<<bfs(nums)<< endl;
	for (int i = 1; i <=N; i++) cout << bool(others & (1 << i)) << ' ';
	cout << "bfs : " << bfs(others) << endl;
	cout << "sum : " << sum << endl;
	*/
	for (int i = here + 1; i <= N; i++) {
		dfs(nums | (1 << i), others - (1 << i), i, sum + input[i], count + 1);
	}
	
}
int main() {
	cin >> N;
	adj.resize(N + 1);
	input.resize(N + 1);
	//visited.resize(N + 1);
	for (int i = 1; i <= N; i++) cin >> input[i];
	for (int i = 1; i <= N; i++) check += input[i];

	for (int i = 1; i <= N; i++) {
		int x; cin >> x;
		for (int j = 0; j < x; j++) {
			int y; cin >> y;
			adj[i].push_back(y);
		}
	}
	dfs(0, (1 << (N+1)) - 1, 0, 0, 0);
	if (answer == 987654321) cout << -1 << endl;
	else cout << answer << endl;
}