//problem link: https://www.acmicpc.net/problem/11656
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
string result[1000];

int main(void){
    cin>>s;
    
    int length = int(s.size());
    for(int i = 0; i < length; i++){
        result[i] = s;
        s.erase(s.begin());
    }

    sort(result, result + length); // 사전순으로 정렬

    for(int i = 0; i < length; i++){
        cout<<result[i]<<'\n';
    }
}
