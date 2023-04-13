#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = a.size();
    set<int> left, right;
    for(auto v : a) right.insert(v);
    
    for(auto ball : a){
        right.erase(ball);
        auto leftIter = left.begin(), rightIter = right.begin();
        left.insert(ball);
        
        if(leftIter == left.end() || rightIter == right.end()) continue;
        // cout<<*leftIter<<' '<<ball<<' '<<*rightIter<<endl;
        if(ball > *leftIter && ball > *rightIter) answer--;
    }
    
    /*
      1. left, right min set
      2. left: 0~cur-1, right: cur ~ n
      3. right.erase(cur)
      4. left의 min값, right의 min값이 모두 cur보다 작으면 answer--
      5. left.insert(cur)
    */
    
    
    return answer;
}