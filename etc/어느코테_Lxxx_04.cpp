#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <sstream>
using namespace std;

// 42분 컷
vector<string> splitStringByCharacter(string str, char c){
    vector<string> splitedStrings;
    istringstream iss(str);

    string token;
    while(getline(iss, token, c)){ // c 문자를 기준으로 문자열이 나누어진다
        splitedStrings.push_back(token);
    }

    return splitedStrings;
}

bool compare(pair<int, string> a, pair<int, string> b){
    if(a.first == b.first){ // 점수가 같으면 
        return a.second < b.second; // 사전순위가 높은걸로
    }

    return a.first > b.first;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";

    vector<pair<int, string> > results; // 총 점수와 그 점수에 해당하는 직업군

    for(int i = 0; i < table.size(); i++){
        // 공백하나 기준으로 문자열들을 나눠 반환받음
        vector<string> splited_table = splitStringByCharacter(table[i], ' ');
        string job = splited_table[0]; // 직업군

        vector<string> languageTable; 
        for(int j = 1; j < 6; j++){ // 직업군별로 추천점수가 높은 언어들 저장
            languageTable.push_back(splited_table[j]);
        }
        int sum = 0;
        for(int k = 0; k < languages.size(); k++){
            string language = languages[k]; // 사용 언어
            int languagePreference = preference[k]; // 사용 언어의 선호도
            int score = 0;
            for(int l = 0; l < languageTable.size(); l++){
                if(language == languageTable[l]){
                    score = (5 - l) * languagePreference; 
                }            
            }
            sum += score;
        }

        results.push_back(make_pair(sum, job));
    }
    
    sort(results.begin(), results.end(), compare);
    answer = results[0].second;

    return answer;
}

int main(void){
    /* 테스트 케이스 1번 */
    /*
    vector<string> table;
    table.push_back("SI JAVA JAVASCRIPT SQL PHYTHON C#");
    table.push_back("CONTENTS JAVASCRIPT JAVA PHYTHON SQL C++");
    table.push_back("HARDWARE C C++ PHYTHON JAVA JAVASCRIPT");
    table.push_back("PORTAL JAVA JAVASCRIPT PHYTHON KOTLIN PHP");
    table.push_back("GAME C++ C# JAVASCRIPT C JAVA");
    vector<string> languages;
    languages.push_back("PHYTHON");
    languages.push_back("C++");
    languages.push_back("SQL");
    vector<int> preference;
    preference.push_back(7);
    preference.push_back(5);
    preference.push_back(5);
    */


    /* 테스트 케이스 2번 */
    /*
    vector<string> table;
    table.push_back("SI JAVA JAVASCRIPT SQL PHYTHON C#");
    table.push_back("CONTENTS JAVASCRIPT JAVA PHYTHON SQL C++");
    table.push_back("HARDWARE C C++ PHYTHON JAVA JAVASCRIPT");
    table.push_back("PORTAL JAVA JAVASCRIPT PHYTHON KOTLIN PHP");
    table.push_back("GAME C++ C# JAVASCRIPT C JAVA");
    vector<string> languages;
    languages.push_back("JAVA");
    languages.push_back("JAVASCRIPT");
    vector<int> preference;
    preference.push_back(7);
    preference.push_back(5);
    */

    cout<<solution(table, languages, preference);
}
