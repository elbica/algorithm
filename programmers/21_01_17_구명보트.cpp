#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.rbegin(),people.rend());
    int start = 0, end = people.size()-1;
    while(start <= end){
        
        if(people[start] + people[end] <= limit) end--;
        answer++; start++;
    }

    return answer;
}