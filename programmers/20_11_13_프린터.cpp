#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<int> result = vector<int>(priorities.size());
	//번호, 중요도
	queue<pair<int, int>> input;
	priority_queue<int> pq;
	for (int i = 0; i < priorities.size(); i++) {
		input.push({ i,priorities[i] });
		pq.push(priorities[i]);
	}
	
	int num = 1;
	while (!input.empty()) {
		auto check = input.front(); input.pop();

		if (check.second != pq.top()) {
			input.push(check); 
		}
		else {
			result[check.first] = num++;
			pq.pop();
		}
	}
	

	return result[location];
}