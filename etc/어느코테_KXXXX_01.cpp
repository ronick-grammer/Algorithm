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

string translate(string s){
    if(s == "zero")
        return "0";
    if(s == "one")
        return "1";
    if(s == "two")
        return "2";
    if(s == "three")
        return "3";
    if(s == "four")
        return "4";
    if(s == "five")
        return "5";
    if(s == "six")
        return "6";
    if(s == "seven")
        return "7";
    if(s == "eight")
        return "8";
    if(s == "nine")
        return "9";

    return "";
}

int solution(string s) {
    int answer = 0;

    for(int j = 0; j < 10; j++){
        int pos = 0;
        while((pos = s.find(numbers[j], pos)) != string::npos){
            s.replace(pos, numbers[j].size(), translate(numbers[j]));
            pos++; // 인덱스 1 증가
        }
     }
    answer = stoi(s);
    return answer;
}
