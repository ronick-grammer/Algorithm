#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
// 문자를 숫자로 변환하기 
// 테스트 케이스
"one4seveneight"  ->	1478
"23four5six7"	->   234567
"2three45sixseven" ->	234567
"123" ->	123
*/
string numbers[10] = {"zero", "one", "two", "three", "four", 
                     "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    int answer = 0;

    for(int j = 0; j < 10; j++){
        int pos = 0;
        while((pos = s.find(numbers[j], pos)) != string::npos){
            s.replace(pos, numbers[j].size(), to_string(j));
            pos++; // 인덱스 1 증가
        }
     }
    answer = stoi(s);
    return answer;
}
