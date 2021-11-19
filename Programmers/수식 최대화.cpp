//problem link: https://programmers.co.kr/learn/courses/30/lessons/67257
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char operatorChars[3] = {'*', '-', '+'};

long long calculate(long long v1, long long v2, char op) {
    switch (op) {
        case '*': return v1 * v2;
        case '+': return v1 + v2;
        case '-': return v1 - v2;
        default: return -1;
    }
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<long long> operands; //  피연산자들
    vector<char> operators; // 연산자들
    int pos = 0;
    
    for(int i = 0; i < expression.size(); i++) {
        // 연산자와 피연산자 각각 나눠담기
        if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
            operators.push_back(expression[i]);
            operands.push_back(stoi(expression.substr(pos, i - pos)));
            pos = i + 1;
        }
    }
    operands.push_back(stoi(expression.substr(pos)));
    
    // 연산자들의 모든 우선순위 경우의 수를 구하기 위해 
    // next_permutation 함수를 사용하려면 오름차순으로 정렬을 해야함
    sort(operatorChars, operatorChars + 3);
    do {
        // 연산자와 피연산자들의 임시 객체
        vector<long long> temp_operands = operands;
        vector<char> temp_operators = operators;
        
        for(int i = 0; i < 3; i++) {
            
            // 연산자 우선순위에 맞게 계산시작
            for(int j = 0; j < temp_operators.size(); j++) {
                if(operatorChars[i] == temp_operators[j]) {
                    // 연산한 결과값을 앞에 넣기
                    temp_operands[j] = calculate(temp_operands[j], temp_operands[j+1], temp_operators[j]);
                    
                    // 연산이 끝난 연산자와 피연산자는 삭제해주기
                    // 삭제로 인해 사이즈의 변화에 따른 인덱스 호환을 위해 j를 1씩 감소
                    temp_operators.erase(temp_operators.begin() + j);
                    temp_operands.erase(temp_operands.begin() + j + 1);
                    
                    j--;
                }
            }
            
        }
        
        // 최대값 구하기
        answer = max(answer, abs(temp_operands[0]));

    }while(next_permutation(operatorChars, operatorChars + 3));
    
    return answer;
}
