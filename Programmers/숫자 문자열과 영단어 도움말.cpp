// problem link: https://programmers.co.kr/learn/courses/30/lessons/81301
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 인덱스와 일치하는 숫자의 문자
string numbers[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    int answer = 0;
    string str_answer = "";
    int pos = 0;
    
    while(pos < s.size()) {
        
        if(!(s[pos] >= '0' && s[pos] <= '9')) { // 숫자가 아니라면
            for(int i = 0; i <= 9; i++) { // 해당하는 숫자 문자과 일치하는 문자열을 숫자 문자열로 바꿔줌
                string translated = s.substr(pos, numbers[i].size());
                if(translated == numbers[i]) {
                    str_answer += to_string(i);
                    pos += translated.size();
                    break;
                }
            }
        } else {
            str_answer += s[pos];
            pos++;
        }
    }
    
    answer = stoi(str_answer); // 마지막에 변환
    return answer;
}
