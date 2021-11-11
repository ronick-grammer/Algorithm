//problm link: https://programmers.co.kr/learn/courses/30/lessons/12933
#include <string>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    // 문자열로 변환 -> 내림차순으로 정렬 -> 이걸 long long 타입으로 변환
    string number_str = to_string(n);
    sort(number_str.begin(), number_str.end(), greater<>());
    answer = stoll(number_str);
    
    return answer;
}
