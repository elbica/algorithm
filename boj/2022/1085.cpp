//
// Created by Kim So Hee on 2022/06/28.
//

#include <bits/stdc++.h>

using namespace std;


int main(){
    int x,y,w,h;
    cin>> x>>y>>w>>h;
    int answer= 987654321;
    answer = min(answer, h-y);
    answer = min(answer, y);
    answer = min(w-x, answer);
    answer = min(x, answer);
    cout<<answer;
}

