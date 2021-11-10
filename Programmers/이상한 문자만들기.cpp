#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> splited;
    
    int pos = 0; // 공백 위치 
    int current_index = 0; // 현재 위치
    
    // 공백기준으로 문자열 분리하기
    while((pos = s.find(" ", pos)) != string::npos) {
        splited.push_back(s.substr(current_index, pos - current_index));
        
        pos++;
        current_index = pos;
    }
    // 마지막 문자열
    splited.push_back(s.substr(current_index));
    
    for(int i = 0; i < splited.size(); i++) {
        for(int j = 0; j < splited[i].size(); j++) {
            // 홀수 위치면 대문자로 짝수 위치면 소문자로
            if((j + 1) % 2 == 1) {
                splited[i][j] = toupper(splited[i][j]);
            } else {
                splited[i][j] = tolower(splited[i][j]);
            }
        }
        
        answer += splited[i] + " ";
    }
    
    // 뒤에 있는 빈칸 지우기
    answer.erase(answer.end() - 1);
    
    return answer;
}
