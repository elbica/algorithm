#include <string>
#include <vector>
#include <algorithm>
#define MOD  1'000'000'007

using namespace std;
int dp[100'111];
int solution(int n, vector<int> money) {
    sort(money.begin(), money.end());
    dp[0] = 1;
    for(auto m : money){
        for(int i=m; i<= n; i++){
            dp[i] = (dp[i] + dp[i-m]) % MOD;
        }
        
    }
    
    return dp[n] % MOD;
}