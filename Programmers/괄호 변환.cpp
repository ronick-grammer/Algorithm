#include <string>
using namespace std;

//problem link: https://programmers.co.kr/learn/courses/30/lessons/60058

int getSplitedIndex(string s){ // 균형잡힌 괄호 문자열의 인덱스 반환
    int count_left = 0;
    int count_right = 0;
    
    if(s[0] == ')'){
        count_right++;
    }
    else{
        count_left++;
    }

    for(int index = 1; index < s.length(); index++){
        if(s[index] == ')'){
            count_right++;
        }
        else{
            count_left++;
        }

        if(count_right == count_left){
            return index;
        }
    }

    return -1;
}

bool isCorrect(string s){ // 올바른 괄호 문자열인지 확인
    int count_left = 0;

    for(int index = 0; index < s.length(); index++){

        if(s[index] == ')'){
            if(count_left == 0){
                return false;
            }
            count_left--;
        }
        else{
            count_left++;
        }
    }

    return true;
}

string solution(string p) {
    if(p == ""){
        return p;
    }
    string answer = "";

    int index_splited = getSplitedIndex(p);
    string u = p.substr(0, index_splited + 1);
    string v = p.substr(index_splited + 1);
    
    if(isCorrect(u)){
        answer += u + solution(v);
    }
    else{
        answer = "(" + solution(v);
        answer += ")";

        u = (u.substr(1, u.length() - 2));

        for(int i = 0; i < u.length(); i++){
            if(u[i] == ')'){
                u[i] = '(';
            }
            else{
                u[i] = ')';
            }
        }
        answer += u;
    }
    return answer;
}
