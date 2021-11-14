//problem link: https://programmers.co.kr/learn/courses/30/lessons/12948
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";

    // 핸드폰 뒤의 네자리를 제외하고 전부 '*'로 채우기
    answer.append(phone_number.size() - 4, '*');
    answer += phone_number.substr(phone_number.size() - 4);

    return answer;
}
