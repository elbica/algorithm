#include <string>
#include <vector>
#include<iostream>
#include <queue> 
#include<algorithm>

using namespace std;
int visited[30][30];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};


struct pos {
    int cost; int y; int x; int prevY; int prevX; 
    bool operator<(const pos& a) const {
        return cost < a.cost; 
    }
};

int solution(vector<vector<int>> board) {
    int answer = 0, size = board.size();
    
    priority_queue<pos> q;
    q.push({0, 0, 0 , -1, -1});
    fill(&visited[0][0], &visited[29][30], 987654321);
    visited[0][0] = 0;
    
    while(!q.empty()){
        auto [cost, y, x, prevY, prevX] = q.top(); q.pop();
        for(int i=0; i<4; i++){
            int nextY = y + dy[i], nextX = x+dx[i];
            if(nextY < 0 || nextY >= size || nextX < 0 || nextX >= size) continue;
            if(board[nextY][nextX]) continue;
            int money = (prevY == nextY || prevX == nextX || prevX == -1) ? 100 : 600;
            
            if(visited[nextY][nextX] < cost + money) continue;
            visited[nextY][nextX] = cost+money;
            // cout<<cost + money<<' '<<nextY<<' '<<nextX<<' '<<y<<' '<<x<<' '<<prevY<<' '<<prevX<<' '<<money<<endl;
            
            q.push({cost+money, nextY, nextX, y, x});
            
        }
    }
    

    return visited[size-1][size-1];
}