#include<bits/stdc++.h>
using namespace std;

int arr[2200][2200], N;
int result[3];

void recur(int firstX, int firstY, int secondX, int secondY){

    if(secondX <= firstX + 1) {result[arr[firstY][firstX]+1]++; return;}
    //cout<<firstX<<' '<<firstY<<' '<<secondX<<' '<<secondY<<endl;
    int check = arr[firstY][firstX];
    bool flag = false;
    for(int i=firstY; i<secondY; i++)
        for(int j=firstX; j<secondX; j++)
            if(arr[i][j]!=check) flag = true;
    
    if(flag){
        int plus = (secondX-firstX)/3;
        for(int i=0; i<3; i++){
            recur(firstX,firstY+i*plus,firstX+plus,firstY+(i+1)*plus);
            recur(firstX+plus,firstY+i*plus,firstX+2*plus,firstY+(i+1)*plus);
            recur(firstX+2*plus,firstY+i*plus,firstX+3*plus,firstY+(i+1)*plus);
        }
    }
    else{
        result[++check]++;
    }
}

int main(){
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) cin>>arr[i][j];

    recur(0,0,N,N);
    for(int i=0; i<3; i++) cout<<result[i]<<endl;
}