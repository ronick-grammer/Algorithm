//problem link: https://programmers.co.kr/learn/courses/30/lessons/12934
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    long long sq = sqrt(n);
    (sq * sq == n) ? answer = (sq + 1) * (sq + 1) : answer = -1;
    return answer;
}
