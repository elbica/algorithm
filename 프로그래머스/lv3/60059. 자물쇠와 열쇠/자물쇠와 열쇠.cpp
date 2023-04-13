#include <string>
#include <vector>

using namespace std;
int init[66][66];
int temp[66][66];
int s;
/*
  1. 탐색 시작점 : (20 - size, 20 - size)
  2. 끝점 : (20 + size, 20 + size)
  3. 회전 : (1, 0) -> (0, 2) : (i, j) -> (j, size - i -1)
*/

void tempInit(){
    for(int i=0; i<=65; i++)
        for(int j=0; j<=65; j++)
            temp[i][j] = init[i][j];
}

void keyRotate(vector<vector<int>>& key){
    vector<vector<int>> temp(key.size(), vector<int>(key.size()));
    int s = key.size();
    for(int i=0; i<s; i++)
        for(int j=0; j<s; j++)
            temp[j][s - i - 1] = key[i][j];
    key = temp;
}
bool addKeyToTemp(int y, int x, vector<vector<int>>& key){
    int keySize= key.size();
    for(int i=0; i<keySize; i++)
        for(int j=0; j<keySize; j++)
            temp[y+i][x+j] += key[i][j];
    
    bool ret = true;
     for(int i=0; i<s; i++)
        for(int j=0; j<s; j++)
            if(temp[20+i][20+j]==0 || temp[20+i][20+j]==2) ret = false;
    
    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    for(int i=0; i<lock.size(); i++)
        for(int j=0; j<lock.size(); j++){
            init[20+i][20+j] = lock[i][j];
        }
    
    s = lock.size();
    bool answer = false;
    
    tempInit();
    
    for(int i=20-s; i<= 20+s; i++)
        for(int j=20-s; j<=20+s; j++){
            for(int k=0; k<4; k++){
                // 1. key와 temp check
                // 2. temp (20~ 20+size) 모두 1이면 answer = true;
                if(addKeyToTemp(i, j, key)) answer = true;
                
                // 3. temp = init
                tempInit();
                // 4. key 회전
                keyRotate(key);
            }
        }
    
    return answer;
}