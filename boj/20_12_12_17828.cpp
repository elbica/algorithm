#include<iostream>
using namespace std;
int N,K;
int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>N>>K;
    char arr[26];
    char* output = new char[N];
    //문자들 마다 가치 설정
    for(int i=0;i<26;i++){
        arr[i] = char('A'+i);
    }

    K-=N;
    //예외 처리
    if(25*N<K||K<0){
        cout<<'!'; return 0;
    }
    //뒤에서부터 문자를 채운다
    int idx = N-1;
    while(idx>=0){
        if(K>=25){
            output[idx] = 'Z';
            K-=25;
        }
        else{
            output[idx] = arr[K];
            K-=K;
        } 
        idx--;
    }
    for(int i=0;i<N;i++) cout<<output[i];
}