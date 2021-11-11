//problem link: https://programmers.co.kr/learn/courses/30/lessons/12932
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    // 숫자를 문자열로 변환
    string number_str = to_string(n);
    
    // 각 자리 숫자를 뒤에서부터 담기
    for(int i = number_str.size() - 1; i >= 0; i--) {
        answer.push_back(number_str[i] - '0');
    }
    
    return answer;
}
