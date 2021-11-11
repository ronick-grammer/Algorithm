//problem link: https://programmers.co.kr/learn/courses/30/lessons/12921
#include <string>
#include <vector>
using namespace std;

bool numbers[1000001];

int solution(int n) {
    int answer = 0;
    
    // 에라이 프로토스 테네스의 체 알고리즘 
    // 최초 수의 모든 배수를 합성수로 지정하기
    // 어떤 수의 배수인 수는 무시하기(소수가 아니므로)
    for(int i = 2; i <= n; i++) {
        if(numbers[i]) continue;
        
        for(int j = i * 2; j <= n; j += i) {
            numbers[j] = true;
        }
    }
    
    for(int i = 2; i <= n; i++) {
        if(!numbers[i]) answer++;
    }
    
    return answer;
}
