//problem link: https://programmers.co.kr/learn/courses/30/lessons/12903
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if(s.size() % 2 == 0) { // 가운데 두글자
        answer = s.substr(s.size() / 2 - 1, 2);
    } else{
        answer = s[s.size() / 2];
    }
    
    return answer;
}
