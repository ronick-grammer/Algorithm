//problem link: https://programmers.co.kr/learn/courses/30/lessons/12985
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    // 서로 붙을 때까지 반복
    while(!((a % 2 == 0 && b == a - 1) || (a % 2 == 1 && b == a + 1))) {
        
        // a와 b는 계속 이김
        a = (a % 2 == 0) ? a / 2 : a / 2 + 1;
        b = (b % 2 == 0) ? b / 2 : b / 2 + 1;
        
        answer++;
        
    } 

    return answer;
}
