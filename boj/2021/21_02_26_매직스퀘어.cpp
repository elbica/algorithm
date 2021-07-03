#include<bits/stdc++.h>
using namespace std;

int input[10], answer = 987654;

void recur(int idx, int check, int arr[]){
    if(idx!=0 && idx%3==0){
        if(arr[idx]+arr[idx-1]+arr[idx-2]!=check) return;
    }
    if(idx==9){
        if(arr[idx]+arr[idx-3]+arr[idx-6]!=check) return;
        if(arr[idx-1]+arr[idx-4]+arr[idx-7]!=check) return;
        if(arr[idx-2]+arr[idx-5]+arr[idx-8]!=check) return;
        if(arr[idx]+arr[idx-4]+arr[idx-8]!=check) return;
        if(arr[idx-2]+arr[idx-4]+arr[idx-6]!=check) return;
        bool te[10] = {0,};
        for(int i=1; i<=9; i++){
            if(te[arr[i]]) return;
            te[arr[i]] = true;
        }
        int temp = 0;
        for(int i=1; i<=9; i++) temp += abs(input[i]-arr[i]);
        answer = min(answer,temp); return;
    }
    for(int i=1; i<=9; i++) {
        arr[idx+1] = i;
        recur(idx+1,check,arr);
        }
}
int main(){
    for(int i=1; i<=9; i++) cin>>input[i];
    int arr[10];
    recur(0,15,arr);
    cout<<answer;

}