#include <string>
#include <vector>
#include <sstream>
#include<algorithm>
using namespace std;

//부분 합 이용
int solution(vector<string> lines) {
	int answer = 0;	
	vector<pair<int, int>> result;
	for (int i = 0; i < lines.size(); i++) {
		stringstream ss(lines[i]); string temp;
		ss >> temp; ss >> temp;

		int number = 0;
		number += 60 * 60000 * stod(temp.substr(0, 2));
		number += 60000 * stod(temp.substr(3, 5));
		number += 1000 * stod(temp.substr(6, temp.size()));

		ss >> temp;
		int second = 1000 * stod(temp.substr(0, temp.size() - 1));

		int insertIdx = number - second - 998;
		int deleteIdx = number + 1;

		result.push_back({ insertIdx,1 });
		result.push_back({ deleteIdx,-1 });
	}
	//시간 복잡도 O(n logn)
	sort(result.begin(), result.end());
	int check = 0;
	for (auto r : result) {
		check += r.second;
		if (check > answer) answer = check;
	}
	return answer;
}