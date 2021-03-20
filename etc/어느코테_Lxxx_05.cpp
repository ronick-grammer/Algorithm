#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 규칙 2 - 4
char rule2_4[9] = {'~', '!', '@', '#', '$', '%', '^', '&', '*'};

//1번 규칙
bool rule_1(const string& str){
    return (str.size() >= 8 && str.size() <= 15);
}

//2 번 규칙
pair<bool, int> rule_2(const string& str){
    bool upper = false;
    bool lower = false;
    bool number = false;
    bool special = false;

    bool validation = true;
    for(int i = 0; i < str.size(); i++){
        bool possible = false;
        if(str[i] >= 'A' && str[i] <= 'Z'){
            if(!upper)
                upper = true;

            possible = true;
        }
        else if(str[i] >= 'a' && str[i] <= 'z'){
            if(!lower)
                lower = true;

            possible = true;
        }
        else if(str[i] >= '0' && str[i] <= '9'){
            if(!number) 
                number = true;

            possible = true;
        }
        else{
            for(int j = 0; j < 9; j++){
                if(str[i] == rule2_4[j]){
                    if(!special)
                        special = true;

                    possible = true;
                    break;
                }
            }
        }

        if(!possible){
            if(validation)
                validation = false;
        }
    }

    int count = 0;
    if(upper){
        count++;
    }
    if(lower){
        count++;
    }
    if(number){
        count++;
    }
    if(special){
        count++;
    }

    return make_pair(validation, count);
}

bool rule_3(int count){
    if(count >= 3){
        return true;
    }
    return false;
}

bool rule_4(const string &str){

    int successiveCount = 1;
    char successiveCharacter = str[0];
    for(int i = 1; i < str.size(); i++){
        char currentCharacter = str[i];
        if(successiveCharacter == currentCharacter){
            successiveCount++;
            if(successiveCount >= 4){
                return false;
            }
        }
        else{
            successiveCharacter = currentCharacter;
            successiveCount = 1;
        }
    }
    return true;
}

bool rule_5(string& str){ // 마지막 룰이기에 그냥 문자열 변경을 허용하겠음

    sort(str.begin(), str.end()); // 이진탐색으로 같은 문자열 5개 이상이 있는지 확인
    
    int next_index = 0;
    for(int i = 0; i < str.size(); i = next_index){
        string::iterator left = lower_bound(str.begin(), str.end(), str[i]);
        string::iterator right = upper_bound(str.begin(), str.end(), str[i]);
        int sameCharacterCount = right - left;
        
        if(sameCharacterCount >= 5){
            return false;
        }
        next_index = right - str.begin();
    }
    return true;
}

vector<int> solution(string inp_str) {
    vector<int> answer;

    if(!rule_1(inp_str)){
        answer.push_back(1);
    }
    
    pair<bool, int> get_rule_2 = rule_2(inp_str);
    if(!get_rule_2.first){
        answer.push_back(2);
    }

    if(!rule_3(get_rule_2.second)){
        answer.push_back(3);
    }
    
    if(!rule_4(inp_str)){
        answer.push_back(4);
    }
    
    if(!rule_5(inp_str)){
        answer.push_back(5);
    }

    if(answer.size() == 0){
        answer.push_back(0);
    }
    
    return answer;
}

int main(void){
    string inp_str = "AaTa+!12-3";
    //string inp_str = "aaaaZZZZ)";
    //string inp_str = "CaCbCgCdC8888334A";
    //string inp_str = "UUUUU";
    //string inp_str = "ZzZz9Z824";

    vector<int> result = solution(inp_str);
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<' ';
    }
    cout<<'\n';
}
