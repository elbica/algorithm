#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int dp[2501][2501];
int solution(string s)
{
    for(int i=0; i<=2500; i++) dp[i][i] = 1;
    for(int i=0; i<s.size()-1; i++){ if(s[i] == s[i+1]) dp[i][i+1] = 2;}
    /*
      dp[i][j] : 
       1. s[i] == s[j], dp[i+1][j-1] + 1
       2. else, dp[i+1][j-1]
    */
    for(int i=2; i<s.size(); i++)
        for(int j=0; j+i <s.size(); j++){
            int start = j, end = j + i;
            if(s[start] == s[end] && start+1 < s.size() && end >=1 && dp[start+1][end-1]) dp[start][end] = dp[start+1][end-1] + 2;
            // else dp[start][end] = max( {dp[start+1][end-1], dp[start+1][end], dp[start][end-1]});
            else dp[start][end] = 0;
        }
    
    int answer=0;

    return *max_element(&dp[0][0], &dp[2500][2501]);
}