#include <string>
#include <vector>
#include<iostream>
#include <algorithm>
using namespace std;

int arr[101];
int find(int cur){
   if(cur == arr[cur]) return cur;
    return arr[cur] = find(arr[cur]);
}
void merge(int x, int y){
    int p1 = find(x), p2 = find(y);
    arr[p1] = p2;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), [](auto a,auto b){return a[2] < b[2]; });
    for(int i=0; i<n; i++) arr[i] = i;
    
    for(auto c: costs){
        int left = c[0], right =c[1], cost =c[2];
         // cout<<left<<' '<<right<<' '<<cost<<endl;
        if(find(left) == find(right)) continue;
        // cout<<left<<' '<<right<<' '<<cost<<endl;
        merge(left, right);
        answer+= cost;
    }
    
    return answer;
}