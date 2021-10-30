//problem link: https://programmers.co.kr/learn/courses/30/lessons/42862
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> students(n+1, 1); // 모든 학생이 체육복을 가지고 있었음

    for(int i = 0; i < lost.size(); i++) {
        students[lost[i]]--; // 스틸당함
    }
    for(int i = 0; i < reserve.size(); i++) {
        students[reserve[i]]++; // 여유분
    }
    
    for(int i = 1; i <= n; i++) {
        // 앞에 있는 학생이 여유분을 가지고 있으면 뺏음
        if(students[i] == 0 && students[i - 1] == 2) { 
            students[i] = students[i - 1] = 1; 
        }
        // 앞에 있는 학생이 체육복이 없으면 강탈당함
        else if(students[i] == 2 && students[i - 1] == 0) {
            students[i] = students[i - 1] = 1;
        }
    }
    
    for(int i = 1; i <= n; i++) { // 체육복을 가지고 있는 학생 카운트 ㅇㅇ
        if(students[i] >= 1) answer++;
    }
    
    return answer;
}
