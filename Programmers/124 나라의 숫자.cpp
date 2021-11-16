//problem link: https://programmers.co.kr/learn/courses/30/lessons/12899
#include <string>
#include <vector>
using namespace std;

string notation[3] = {"4", "1", "2"};

string solution(int n) {
    string answer = "";
    
    int divided = n;
    while(divided != 0){
        
        n = divided % 3; 
        answer = notation[n] + answer; // 나머지를 가장 뒤에서 부터 붙이기
        
        divided /= 3; // 나눈 몫
        if(n == 0) divided--; // 나머지가 0이었으면 몫에서 1을 빼기
    }
    
    return answer;
}
