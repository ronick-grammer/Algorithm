#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// problem link: https://programmers.co.kr/learn/courses/30/lessons/60057

int solution(string s) {
    int answer;
    int min_characters = s.size(); // 압축된 문자열중 가장 문자수가 적은 수를 저장
    int mid = s.size() / 2; 

    for(int i = 1; i <= mid; i++){ // 반으로 자른 단위까지만(반을 넘어가게 자르는 경우는 없다)
        string each_str = ""; // 각 단위별로 압축된 문자열
        string prev_str; // 각 단위별로 자른 왼쪽 문자열
        string current_str; // 각 단위별로 자른 오른쪽 문자열
        int count = 1; // 연속되는 두 문자열의 반복 횟수

        prev_str = s.substr(0, i); // 우선 가장 왼쪽 문자열을 넣어준다

        for(int j = i; j < s.size(); j += i){  
            current_str = s.substr(j, i); // 단위별로 반복해서 자른다
            if(prev_str.compare(current_str) == 0){ // 두 문자열이 같다는 것은 연속한다는 것을 의미한다
                count++; // 그러므로 연속 횟수를 증가
            }
            else{ // 두 문자열이 다르다면
                if(count >= 2){  // 연속하는 횟수를 체크하여 2개 이상일 경우
                    each_str += (to_string(count) + prev_str); // 직전 연속횟수 + 직전 문자열을 차례로 저장
                    count = 1; // 연속 횟수는 다시 초기화
                }
                else{     // 연속횟수가 1개 이하이면
                    each_str += prev_str; // 그냥 그대로 직전 문자열 저장
                }
            }
            prev_str = current_str; // 그렇게 반복하여 준다
        }
        // 위에서 다 반복을 하였어도 마지막 문자열은 아직 처리되지 않았다
        // 그러므로 마지막 연속 횟수와 마지막 문자열을 체크해준다
        if(count >= 2){ 
            each_str += (to_string(count) + prev_str);
        }
        else{
            each_str += prev_str;
        }

        min_characters = min(min_characters, (int)each_str.size()); // 압축된 문자열의 사이즈중 가장 작은 사이즈를 저장해준다
    }
    answer = min_characters;

    return answer;
}
