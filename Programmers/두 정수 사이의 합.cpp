//problem link: https://programmers.co.kr/learn/courses/30/lessons/12912
#include <string>
#include <vector>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    // a 가 무조건 작은 수 가지게 하기
    if (a > b) swap(a, b);
    
    for(int i = a; i <= b; i++) {
        answer += i;
    }
    
    return answer;
}
