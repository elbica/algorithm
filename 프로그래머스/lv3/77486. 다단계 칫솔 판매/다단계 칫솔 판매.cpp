#include <string>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <iostream>

using namespace std;
unordered_map<string, int> result; 
unordered_map<string, string> parent;


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    result["-"] = 0;
    for(auto e : enroll) result[e] = 0;
    for(int i=0; i<enroll.size(); i++){
        parent[enroll[i]] = referral[i];
    }
    
    for(int i=0; i<seller.size(); i++){
        /*
          1. cur = (price / 10) * 9
          2. next = price / 10;
          3. floor(next) == 0, result[seller] += price/10, break;
          4. else result[seller] += cur,
        */
        int price = amount[i] * 100;
        string sell = seller[i];
        while(1){
            int cur = price - (price/10), next = price/10;
            // cout<<cur<<' '<<sell<<endl;
            
            if(floor(next) == 0){
                result[sell] += price; break;
            }
            result[sell] += cur;
            sell = parent[sell];
            price = next;
        }
    }
    
    
    vector<int> answer;
    for(auto e : enroll) answer.push_back(result[e]);
    
    return answer;
}