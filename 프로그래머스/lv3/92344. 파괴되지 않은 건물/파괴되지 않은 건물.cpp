#include <string>
#include <vector>

using namespace std;

int sum[1002][1002];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    for(auto s : skill){
        int type = s[0], r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4], degree = s[5];
        if(type == 1){
            degree = -degree;
        }
        
        // for(int i=r1; i<=r2; i++){
        //     sum[i][c1] += degree;
        //     sum[i][c2+1] -= degree;
        // }
        sum[r1][c1] += degree;
        sum[r1][c2+1] -= degree;
        sum[r2+1][c1] -= degree;
        sum[r2+1][c2+1] += degree;
    }
    
    
    
    for(int i=0; i<board.size(); i++){
        for(int j=1; j<board[0].size();j++){
            sum[i][j] += sum[i][j-1];
        }
    }
    for(int i=1; i<board.size(); i++){
        for(int j=0; j<board[0].size();j++){
            sum[i][j] += sum[i-1][j];
        }
    }
    
    int answer = 0;
    
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size();j++){
            board[i][j] += sum[i][j];
            if(board[i][j] > 0 )answer++;
        }
    }
    
    return answer;
}