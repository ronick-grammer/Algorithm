//problem link: https://programmers.co.kr/learn/courses/30/lessons/12982
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 잔디 심기용 알고리즘 풀이라 너무 쉽다..
int solution(vector<int> d, int budget) {
    int answer = 0;
    
    // 오름차순 정렬
    sort(d.begin(), d.end());
    
    for(int i = 0; i < d.size(); i++) {
        // 가장 적은 예산을 가지는 부서부터 처리해서 최대값 구하기
        if(budget - d[i] >= 0) {
            budget -= d[i];
            answer++;
        }
    }
    return answer;
}
