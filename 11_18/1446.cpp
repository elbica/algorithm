#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, D, answer;
int input[13][3];

int main() {
	cin >> N >> D;
	for (int i = 0; i < N; i++) 
		// 시작 위치, 도착 위치, 길이
		cin >> input[i][0] >> input[i][1] >> input[i][2];
	
	input[N][0] = input[N][1] = D;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,0 }); // {비용, 도착 위치}

	while (!pq.empty()) {
		int here = pq.top().second; //탐색한 도착 위치
		int dist = -pq.top().first; //걸리는 최소 거리
		pq.pop();

		//종료 조건
		if (here == D) { answer = dist; break; }

		//탐색한 도착 위치보다, 시작 위치가 더 큰 지름길을 큐에 넣는다
		for(int i = 0 ; i <= N; i++)
			if (input[i][0] >= here) {
				int there = input[i][1]; //새로운 도착 위치
				int nextdist = dist + 
					(input[i][0] - here) + input[i][2]; //새로운 최소 거리
				pq.push({ -nextdist,there });
			}
	}
	cout << answer << endl;
}