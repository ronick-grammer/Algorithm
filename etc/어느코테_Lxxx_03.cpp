#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

vector<string> splitStringByString(string str, string split){ 
    vector<string> splitedStrings;  
    
    string newStr = str;
    int pos = 0; // split 문자열의 위치
    int current_index = 0; // 분할해서 담을 문자열의 위치

    // split 문자열이 있는 문자열의 위치를 왼쪽에서부터 찾는다.
    while((pos = newStr.find(split, pos)) != string::npos){ 
        
        splitedStrings.push_back(newStr.substr(current_index, pos - current_index));
        
        pos += split.size(); // 찾았으면 split 문자열을 찾은 위치의 다음 위치부터 찾는다.
        
        current_index = pos; // 분할해서 담을 문자열의 위치
    }
    
    splitedStrings.push_back(newStr.substr(current_index)); // 마지막 문자열을 담는다

    return splitedStrings;
}

// 플래그 이름과 플래그 인자 종류를 나누어서 반환
vector<pair<string, string> > get_flagName_N_agumentType(vector<string> flag_rules){
    vector<pair<string, string> > flagName_N_agumentType; // 플래그 이름과 인자의 종류
    
    for(int i = 0; i < flag_rules.size(); i++){
        vector<string> name_type = splitStringByString(flag_rules[i], " ");
        flagName_N_agumentType.push_back(make_pair(name_type[0], name_type[1]));
    }

    return flagName_N_agumentType;
}

// 공백기준으로 커맨드 라인 명렁어를 단어별로 나누고, 그 문자열들 중에서 플래그 이름과 플래그 인자를 묵은 string 들을 반환한다
vector<vector<string> > splitCommandLineIntoWords(string command){
    vector<string> splited_commandWords;

    splited_commandWords = splitStringByString(command, " "); 
    
    vector<vector<string> > completed;
    int currentIndex = 0;
    for(int i = 0; i < splited_commandWords.size(); i = currentIndex){
        vector<string> s;
        if(splited_commandWords[i][0] == '-'){ // 플래그 이름이라면
            s.push_back(splited_commandWords[i]); // 플래그 이름을 우선 넣고 
            // 플래그 이름 다음에 플래그 인자까지 넣어서 묶어준다. 단, 인자가 없는 NULL 인 경우 그냥 넘어간다
            if((i + 1) < splited_commandWords.size() && splited_commandWords[i + 1][0] != '-'){
                s.push_back(splited_commandWords[i + 1]);
                currentIndex = i + 2; 
            }
            else{
                currentIndex++;
            }
        }
        else{ // 플래그 이름이 아니라도 일단은 넣어준다. - 가 붙지 않은 일반 문자열이라면 후에 유효성에서 거를 수가 있다
            s.push_back(splited_commandWords[i]);
            currentIndex++;
        }
        completed.push_back(s);
    }

    return completed;
}

// 문자열 유효성
bool validateString(const string &str){
    for(int i = 0; i < str.size(); i++){
        if(!(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= 'a' && str[i] <= 'z')){
            return false;
        }
    }
    return true;
}

// 숫자 유효성
bool validateNumber(const string &str){
    for(int i = 0; i < str.size(); i++){
        if(!(str[i] >= '0' && str[i] <= '9')){
            return false;
        }
    }
    return true;
}

// 커맨드 라인 유효성 확인
bool validateCommandLine(string program, const vector<pair<string, string> > &flagName_N_agumentType, const vector<vector<string> > &commandsLineWords)
{
    string program_command = commandsLineWords[0][0]; // 프로그램 이름이 다르면 바로 flase 반환
    if(program_command != program){
        return false;
    }

    for(int i = 0; i < flagName_N_agumentType.size(); i++){
        string flagName = flagName_N_agumentType[i].first; // 플래그 이름
        string flagArgument = flagName_N_agumentType[i].second; // 플래그 인자 종류
        
        for(int j = 1; j < commandsLineWords.size(); j++){
            
            string command_flag_name = commandsLineWords[j][0]; // 커맨드라인의 플래그 이름
            
            if(command_flag_name[0] != '-'){ // 플래그 이름인데 '-'가 앞글자에 없다면 잘못된 커맨드 라인을 쓴것이니 false
                return false;
            }

            if(flagName == command_flag_name){ // 플래그 이름과 커맨드라인의 플래그 이름이 일치하다면

                if(flagArgument == "NULL"){
                    if(commandsLineWords[j].size() >= 2){ // 플래그 인자가 null인데 인자값이 있으면 false
                        return false;
                    }
                }
                else if(commandsLineWords[j].size() < 2){ // 플래그 인자가 null이 아닌데 인자값이 없으면 false
                    return false;
                }

                string command_flag_argument = commandsLineWords[j][1];   

                if(flagArgument == "STRING"){ // 문자열 유효성
                    
                    if(!validateString(command_flag_argument)){
                        return false;
                    }
                }
                else if(flagArgument == "NUMBER"){ // 숫자 유효성
                    if(!validateNumber(command_flag_argument)){
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
    vector<bool> answer;

    // 플래그 이름과 인자의 종류
    vector<pair<string, string> > flagName_N_argumentType;
    flagName_N_argumentType = get_flagName_N_agumentType(flag_rules);
    
    vector<bool> result;
    for(int i = 0; i < commands.size(); i++){
        // 각 커맨드 라인의 유효성을 확인해준다
        vector<vector<string> > commandsLineWords = splitCommandLineIntoWords(commands[i]);
        bool validation = validateCommandLine(program, flagName_N_argumentType, commandsLineWords);
        
        answer.push_back(validation);
    }

    return answer;
}

int main(void){
    /* 테스트 케이스 1 */
    
    string program = "line";
    vector<string> flag_rules;
    flag_rules.push_back("-s STRING");
    flag_rules.push_back("-n NUMBER");
    flag_rules.push_back("-e NULL");
    vector<string> commands;
    commands.push_back("line -n 100 -s hi -e");
    commands.push_back("lien -s Bye");
    

    /* 테스트 케이스 2 */
    /*
    string program = "line";
    vector<string> flag_rules;
    flag_rules.push_back("-s STRING");
    flag_rules.push_back("-n NUMBER");
    flag_rules.push_back("-e NULL");
    vector<string> commands;
    commands.push_back("line -s 123 n HI");
    commands.push_back("line fun");
    */

    vector<bool> result = solution(program, flag_rules, commands);
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<' ';
    }
    cout<<'\n';
}
