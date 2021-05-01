#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> stak;

int solution(string inputString){
    int count = 0; // 올바른 괄호 쌍 갯수

    for(int i = 0; i < inputString.size(); i++){
        if(inputString[i] == '[' || inputString[i] == '(' || inputString[i] == '{' || inputString[i] == '<')
        {
            stak.push(inputString[i]);
        }
        else if(inputString[i] == ']' || inputString[i] == ')' || inputString[i] == '}' || inputString[i] == '>')
        {
            
            if(stak.empty()) // 첫 문자가 닫는 괄호면 음수 인덱스 반환
                return -i;

            char c = stak.top();
            if(c == '[')
            {
                if(inputString[i] == ']'){
                    stak.pop();
                    count++;
                }
                else
                    return -i; 
            }
            else if(c == '(')
            {
                if(inputString[i] == ')'){
                    stak.pop();
                    count++;
                }
                else
                    return -i;
            }
            else if(c == '{')
            {
                if(inputString[i] == '}'){
                    stak.pop();
                    count++;
                }
                else
                    return -i;
            }
            else if(c == '<')
            {
                if(inputString[i] == '>'){
                    stak.pop();
                    count++;
                }
                else
                    return -i;
            }
        }
    }

    if(!stak.empty()){ // 괄호가 열려 있는 상태로 문자열이 끝나면 마지막 음수 인덱스 반환
        return -(inputString.size() - 1);
    }

    return count;
}

int main(void){
    string input;
    getline(cin, input);

    cout<<solution(input)<<'\n';
}
