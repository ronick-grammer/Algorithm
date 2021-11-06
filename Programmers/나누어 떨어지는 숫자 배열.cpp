//problem link: https://programmers.co.kr/learn/courses/30/lessons/12910
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int i = 0; i < arr.size(); i++) {
        // 나누어 떨어지는 것만 저장
        if(arr[i] % divisor == 0) {
            answer.push_back(arr[i]);
        }
    }
    
    // 정렬하기
    sort(answer.begin(), answer.end());
    
    // 하나도 없으면 -1 삽입
    if(answer.size() == 0) answer.push_back(-1);
    
    return answer;
}
