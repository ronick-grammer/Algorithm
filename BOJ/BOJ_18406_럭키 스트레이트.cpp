#include <iostream>
#include <string>
using namespace std;

//problem link: https://www.acmicpc.net/problem/18406

int main(void){
    string s;
    int sum = 0;

    cin>>s;

    for(int i = 0; i < s.size() / 2; i++){ // 왼쪽 부분 자릿수를 더한 합
        sum += s[i] - '0';
    }

    for(int i = s.size() / 2; i < s.size(); i++){ // 오른쪽 부분 자릿수를 더한 합
        sum -= s[i] -'0';
    }

    if(sum == 0){ 
        cout<<"LUCKY"<<endl;
    }
    else{
        cout<<"READY"<<endl;
    }
}   
