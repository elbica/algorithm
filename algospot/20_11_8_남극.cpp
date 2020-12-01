#include<iostream>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;

int n;
double dist[101][101];
vector<pair<double, double>> input;//��ǥ�� ���� ����

//��� �������� �Ÿ� d ���Ϸ� ���� �� �� �ִ°�?
bool decision(double d) {
	//bfs ���
	vector<bool> visited(n, false);
	//0��° �������� Ž���Ѵ�
	visited[0] = true;
	queue<int> q;
	q.push(0);

	int seen = 0; //������ �� �� �־����� üũ
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		++seen;
		for(int there=0;there<n;there++)
			//�湮���� �ʾҰ�, �Ÿ��� d���� �۴ٸ� ť�� �ִ´�
			if (!visited[there] && dist[here][there] <= d) {
				visited[there] = true;
				q.push(there);
			}
	}
	//������ ť�� ��� �־��ٸ� true
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
//��ó�� : ���� �� �Ÿ����� ����Ѵ�
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
		//�Ҽ��� ��° �ڸ����� �ݿø�
		answer = round(answer * 100) / 100.0;

		cout << setprecision(2) << fixed;
		cout << answer<< endl;
	}
}