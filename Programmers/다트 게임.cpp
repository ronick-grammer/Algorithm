//problem link: https://programmers.co.kr/learn/courses/30/lessons/17682
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
// 뭐이렇게 꼬아 매듭임?

int results[3];

int getPowValue(char c) {
    switch(c) {
        case 'S': return 1;
        case 'D': return 2;
        case 'T': return 3;
        default: return 0;
    }
}

int getOptionValue(char c) {
    if(c == '*') return 2;
    else return -1;
}

int solution(string dartResult) {
    int answer = 0;
    
    vector<string> scores;
    
    int current = 0;
    // 각 (점수|보너스|[옵셥]) 값들 분리하자
    for(int i = 2; i < dartResult.size(); i++) {
        if(isdigit(dartResult[i])) {
            scores.push_back(dartResult.substr(current, i - current));
            current = i;
            i++;
        }
    }
    scores.push_back(dartResult.substr(current));
    
    // 다 분리했으니까 연산 시작 ㄱ
    for(int i = 0; i < scores.size(); i++) {
        int number = 0;
        int powValue = 1;
        int optionValue = 1; // xxx: "옵션은 있을수도 있지만 없을수도 있습니다"
           
        // 점수가 10일 경우
        if(isdigit(scores[i][0]) && isdigit(scores[i][1])) {
            number = stoi(scores[i].substr(0, 2)); // 숫자 변환
            powValue = getPowValue(scores[i][2]);
            
            if(scores[i].size() == 4) // 옵션값이 있으면 가져오기
                optionValue = getOptionValue(scores[i][3]);
            
        } else { // 점수가 한 자리 수일 경우
            number = scores[i][0] - '0'; // 숫자 변환
            powValue = getPowValue(scores[i][1]);
            
            if(scores[i].size() == 3) // 옵션값이 있으면 가져오기
                optionValue = getOptionValue(scores[i][2]);
        }
        
        // 두번째 점수부터는 그 전 점수에도 * 옵션 적용시키기
        if(i != 0 && optionValue == 2) { 
            results[i - 1] *= optionValue;
        } 
        
        results[i] = pow(number, powValue) * optionValue;
    }
    
    answer = results[0] + results[1] + results[2]; 
    return answer;
}
