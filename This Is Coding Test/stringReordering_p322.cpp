#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    string s;
    vector<char> characters;
    int sum = 0;

    cin>>s;

    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){ // 숫자만 따로 더해준다
            sum += s[i] - '0';
        }
        else{
            characters.push_back(s[i]); // 문자를 하나씩 추가해준다
        }
    }

    sort(characters.begin(), characters.end()); // 문자를 오름차순 정렬
    
    for(int i = 0; i < characters.size(); i++){
        cout<<characters[i]; // 정렬된 문자 먼저 출력
    }
    
    if(sum != 0) // 숫자가 존재하면 출력
        cout<<sum<<endl; 
}
