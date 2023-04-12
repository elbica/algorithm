#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> times;
    for(auto t : timetable){
        int hour = stoi( t.substr(0,2)), min = stoi(t.substr(3));
        times.push_back(60*hour + min);
    }
    sort(times.begin(), times.end());
    // for(auto t : times) cout<<t<<' ';
    // cout<<endl;
    int start = 540, idx = 0, people = 0;
    int save = n;
    
    int answer = 0;
   
    
    while(n){
        int cnt = 0;
        while(idx < times.size() && times[idx] <= start){
            idx++,  cnt++;
            if(cnt == m){
                // people = 0;
                break;
            }
        }
        start += t; n--;
        if(n==0){
            answer = start - t;
            
            if(cnt == m) answer = times[idx-1] - 1;
            // if( idx < save*t) answer = start - t;
            cout<<start - t<<' '<<idx<<' '<<cnt<<endl;
        }
    }

    
    string hour = to_string(answer/60), min =  to_string(answer%60) ;
    if(hour.length() == 1) hour = "0" + hour;
    if(min.length() == 1) min = "0" + min;
    string result = hour + ":" + min;
    return result;
}