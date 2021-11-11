//problem link: https://programmers.co.kr/learn/courses/30/lessons/77884
#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right; i++) {
        // 약수의 개수 구하기
        int count = 0;
        for(int j = 1; j <= i; j++) {
            if(i % j == 0) count++;
        }
        // 약수의 개수가 짝수면 더하고 홀수면 빼기
        (count % 2 == 0) ? answer += i : answer -= i;
    }
    
    return answer;
}
