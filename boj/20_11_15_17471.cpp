#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int N, check, answer = 987654321;
vector<vector<int>> adj; //인접 리스트
vector<int> input; //인구 수

//선택한 구역들이 실제로 연결되어 있는지 확인한다
bool bfs(int a) {

	vector<bool> visited(11, true);
	int start = 0, Count = 0, temp = 0;

	for (int i = 1; i <= N; i++){

		//선택한 구역의 비트 값은 1이다
		//그 구역들을 제외한 나머지 구역은 방문처리 해주고,
		//선택한 구역은 방문처리 하지 않는다
		bool check = !bool(a & (1 << i));
		visited[i] = check;

		//동시에 탐색 시작 지점과, 탐색 해야할 구역의 개수를 센다
		if (!check) { start = i; temp++; }
	}
	queue<int> q;
	q.push(start); visited[start] = true;

	while (!q.empty()) {
		int here = q.front(); q.pop();
		//실제로 탐색하면서, 탐색된 구역의 개수를 센다
		Count++;

		for (int c : adj[here]) 
			if (!visited[c]) {
				visited[c] = true;
				q.push(c);
			}
	}
	return temp==Count;
}
//비트마스크를 이용해 선택 가능한 구역들의 모든 조합을 만든다
//인자 설명 : 1.선택한 구역, 2.선택하지 않은 구역, 
//			 3.마지막에 선택한 구역, 4.선택한 구역 인구 합, 5.선택한 구역 수
void dfs(int nums, int others, int here, int sum, int count) {

	//8C5 = 8C3이므로 효율적인 계산을 위해 
	//count가 일정 이상 되면 바로 종료한다
	if (count > N / 2) return;

	if (bfs(nums) && bfs(others)) //두 선거구가 연결 가능하면
		answer = min(answer, abs(2 * sum - check)); //답을 갱신한다

	//1 4 2 5 , 1 2 4 5 등 구역을 선택한 순서는 상관 없므로
	//오름차순으로 선택한다
	for (int i = here + 1; i <= N; i++) 
		dfs(nums | (1 << i), others - (1 << i), i, sum + input[i], count + 1);
}
int main() {
	cin >> N;
	adj.resize(N + 1);
	input.resize(N + 1);

	for (int i = 1; i <= N; i++) cin >> input[i];
	for (int i = 1; i <= N; i++) check += input[i];

	for (int i = 1; i <= N; i++) {
		int x; cin >> x;
		for (int j = 0; j < x; j++) {
			int y; cin >> y;
			adj[i].push_back(y);
		}
	}
	dfs(0, (1 << (N + 1)) - 1, 0, 0, 0);
	if (answer == 987654321) cout << -1 << endl;
	else cout << answer << endl;
}
