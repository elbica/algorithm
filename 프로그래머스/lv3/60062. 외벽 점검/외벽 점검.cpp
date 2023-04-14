#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int s = weak.size();
    auto newWeak = weak;
    for(auto w : weak) newWeak.push_back(w+n);
    int answer = 1e9;
    
    sort(dist.begin(), dist.end());
    do{
        // for(auto d : dist) cout<<d<<' ';
        // cout<<endl;
        /*
           1. 시작지점 정하기 : for int start 0 to s-1, weak[start], 끝 지점 : end = start + n
           2. dist 친구들 돌면서 start 옮기기 : for int num 0 to dist.size(), start += dist[num], 
           3. if(start >= end), answer = min(num, answer)
        */
        for(int idx = 0; idx < s; idx++){
            int start = newWeak[idx];
            int end = newWeak[idx + s - 1];
             // cout<<"for "<<start<<' '<<end<<endl;
            for(int num = 0; num < dist.size(); num++){
                // if(dist[0] == 4 && dist[1] == 2 && start >= 10)
            // cout<<start<<' '<<end<<endl;
                
                start += dist[num];
                auto iter = upper_bound(newWeak.begin(), newWeak.end(), start);
                if(iter == newWeak.end() || (start = *iter) > end){
                    answer = min(num + 1, answer);
                    break;
                }
            }
        }
        // cout<<"========"<<endl;
    }while(next_permutation(dist.begin(), dist.end()));
    return answer == 1e9 ? -1 : answer;
}