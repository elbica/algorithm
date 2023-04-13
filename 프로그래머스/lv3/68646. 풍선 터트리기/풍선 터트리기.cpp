#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = a.size();
    
    vector<int> lv(a.size()), rv(a.size());
    int lmin = a[0];
    for(int i=0; i<a.size(); i++){
        lv[i] = lmin;
        lmin = min(lmin, a[i]);
    }
    
    int rmin = a.back();
    for(int i=a.size()-1; i>=0; i--){
        rv[i] = rmin;
        rmin = min(rmin, a[i]);
    }
    
    for(int i=0; i<a.size(); i++){
        int left = lv[i], right = rv[i];
        if(a[i] > left && a[i] > right) answer--;
    }
    
    
    return answer;
}