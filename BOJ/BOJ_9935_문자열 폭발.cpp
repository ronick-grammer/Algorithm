#include <iostream>
#include <string>
using namespace std;

//problem link: https://www.acmicpc.net/problem/9935

// find를 해주지 않는 이유

int main(void){
    string str, explode, result;
    
    cin>>str;
    cin>>explode;
    
    int size_explode = explode.size();
    char endKey = explode[size_explode - 1];
    for(int i = 0; i < str.size(); i++){
        result.push_back(str[i]); // 우선 계속해서 넣어주고

        if(str[i] == endKey){ // 현재 검사중인 문자가 폭발문자열 마지막 문자와 같다면
            bool isEqual = true;
            for(int j = 1; j < size_explode; j++){ // 앞에서 넣어준 문자들도 검사하여 폭발 문자열인지 확인한다.
                if(result[result.size() - 1 - j] != explode[size_explode - 1 - j]){
                    isEqual = false; // 폭발 문자열이 아니라면 나온다
                    break;
                }
            }

            if(isEqual){ // 앞에서 넣어준 문자들이 폭발 문자열이었다면 앞에서 넣어준 폭발 문자열을 빼준다.
                for(int k = 0; k < size_explode; k++){
                    result.pop_back();
                }
            }
        }
    }
    
    if(result.empty()) cout<<"FRULA"; // 실패 
    else cout<<result; // 성공
}
