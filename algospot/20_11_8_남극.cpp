#include<iostream>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;

int n;
double dist[101][101];
vector<pair<double, double>> input;//좌표들 저장 벡터

//모든 기지들을 거리 d 이하로 연결 할 수 있는가?
bool decision(double d) {
	//bfs 사용
	vector<bool> visited(n, false);
	//0번째 기지부터 탐색한다
	visited[0] = true;
	queue<int> q;
	q.push(0);

	int seen = 0; //기지를 몇 개 넣었는지 체크
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		++seen;
		for(int there=0;there<n;there++)
			//방문하지 않았고, 거리가 d보다 작다면 큐에 넣는다
			if (!visited[there] && dist[here][there] <= d) {
				visited[there] = true;
				q.push(there);
			}
	}
	//기지를 큐에 모두 넣었다면 true
	return seen == n;
}
double optimize() {
	double lo = 0, hi = 1416.00;
	for (int it = 0; it < 100; it++) {
		double mid = (lo + hi) / 2;
		if (decision(mid)) hi = mid;
		else lo = mid;
	}
	return hi;
}
//전처리 : 기지 간 거리들을 계산한다
void cal() {
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			double x1 = input[i].first, x2 = input[j].first;
			double y1 = input[i].second, y2 = input[j].second;
			dist[i][j] = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		}
}
int main() {
	int C; cin >> C;
	while (C--) {
		cin >> n;
		input.resize(n);

		for (int i = 0; i < n; i++) 
			cin >> input[i].first >> input[i].second;
		
		cal();
		double answer = optimize();
		//소숫점 셋째 자리에서 반올림
		answer = round(answer * 100) / 100.0;

		cout << setprecision(2) << fixed;
		cout << answer<< endl;
	}
}