//problem link: https://programmers.co.kr/learn/courses/30/lessons/12931
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;
    // 숫자를 문자열로
    string number_str = to_string(n);
    
    // 문자열의 각 문자를 숫자로 변환하여 더하기
    for(int i = 0; i < number_str.size(); i++) {
       answer += number_str[i] - '0';
    }

    return answer;
}
