#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    vector<stack<int>> dolls(board.size(), stack<int>());
    stack<int> result;
    for (int i = board.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j])
                dolls[j].push(board[i][j]);
        }
    }
    for (int m : moves)
    {
        int check = m - 1;
        if (dolls[check].size() == 0)
            continue;
        int pick = dolls[check].top();
        dolls[check].pop();
        if (result.size() != 0 && result.top() == pick)
        {
            result.pop();
            answer += 2;
            continue;
        }
        result.push(pick);
    }

    return answer;
}