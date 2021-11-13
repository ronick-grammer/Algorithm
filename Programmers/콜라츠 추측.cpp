#include <string>
#include <vector>
using namespace std;

int solution(int num) {
    long number = num; // 안정적인 범위
    int answer = 0;
    
    for(int i = 0; i < 500; i++) {
        if(number == 1) return answer;
        
        if(number % 2 == 0) {
            number /= 2;
        } else {
            number = number * 3 + 1;
        }
        answer++;
    }
    
    return -1;
}
