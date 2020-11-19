#include <string>
#include <vector>
#include <set>
#define MAX 1111111111
using namespace std;

int solution(vector<int> a) {
	int answer = 0;
	int leftcheck = MAX;
	set<int> Set;
	for (int i : a) Set.insert(i);
	Set.insert(MAX);

	for (int i : a) {
		bool check1 = false, check2 = false;
		if (i < leftcheck) { leftcheck = i; check1 = true; }
		Set.erase(Set.find(i));
		int rightcheck = *Set.begin();
		if (i < rightcheck) check2 = true;
		if (check1 || check2) answer++;
	}
	return answer;
}