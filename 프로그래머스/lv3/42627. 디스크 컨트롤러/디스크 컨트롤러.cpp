#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0, size = jobs.size();
    sort(jobs.begin(), jobs.end(), [](auto a, auto b){if(a[0]!=b[0]) return a[0] > b[0]; else return a[1] > b[1]; });
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    while(!jobs.empty()){
    auto back = jobs.back();
    long long time = back[0];
    pq.push({back[1], back[0]}); jobs.pop_back();
    
    while(!pq.empty()){
        auto [cost, start] = pq.top(); pq.pop();
        // cout<<start<< ' '<<cost<<' '<<time<<endl;
        time += cost;
        answer += time - start;
        while(!jobs.empty()){
            auto back = jobs.back();
            if(back[0] > time) break;
            pq.push({back[1], back[0]}); jobs.pop_back();
        }
    }
    }
    // cout<<answer<<endl;
    /* 
      1. pq에서 작업을 하나 꺼내온다 ({소요 시간, 요청 시간})
      2. 현재 시간 time에 꺼낸 작업의 소요 시간을 더한다.
      3. answer += time - 요청 시간
      4. time보다 요청 시간이 작은 jobs.back()들을 pq에 넣는다
    */
    
    return answer/size;
}