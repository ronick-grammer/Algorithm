#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

//problem link: https://programmers.co.kr/learn/courses/30/lessons/72412

enum TABLE {
    APPLICANT,
    QUERY
};

class Info{
    public:
    string language;
    string position;
    string experince;
    string food;
    int score;

   Info(string language, string position, string experince, string food, int score){
        this->language = language;
        this->position = position;
        this->experince = experince;
        this->food = food;
        this->score = score;
    }
};

bool comp(pair<int, int> a, pair<int, int> b){ // pair(score, index)
    return a.first < b.first; // 점수 기준 오름차순
}

// str 문자열에서 split 문자열을 기준으로 문자열들을 분할한다
vector<string> splitStringByString(string str, string split, TABLE table){ 
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

    // 마지막 문자열을 담는다
    if(table == QUERY){
        pos = newStr.find(" ", current_index);
        splitedStrings.push_back(newStr.substr(current_index, pos - current_index)); // 조건
        splitedStrings.push_back(newStr.substr(pos + 1)); // 점수
    }
    else{
        splitedStrings.push_back(newStr.substr(current_index)); // 점수
    }

    return splitedStrings;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<Info> applicantInfo;
    vector<Info> queryInfo;
    vector<pair<int, int> > sortedApplicantScore;

    for(int i = 0; i < info.size(); i++){  // " " 문자열 기준으로 문자열들을 분할시킨다
        vector<string> splitedStr = splitStringByString(info[i], " ", APPLICANT);

        applicantInfo.push_back(Info(splitedStr[0], splitedStr[1], splitedStr[2], splitedStr[3], stoi(splitedStr[4])));
        sortedApplicantScore.push_back(make_pair(stoi(splitedStr[4]), i));
    }

    for(int i = 0; i < query.size(); i++){ // " and " 문자열 기준으로 문자열들을 분할시킨다
        vector<string> splitedStr = splitStringByString(query[i], " and ", QUERY);
        
        queryInfo.push_back(Info(splitedStr[0], splitedStr[1], splitedStr[2], splitedStr[3], stoi(splitedStr[4])));
    }
    
    sort(sortedApplicantScore.begin(), sortedApplicantScore.end()); // 찾을 점수를 기준으로 이진 탐색을 위해 정렬

    for(int i = 0; i < queryInfo.size(); i++){
        int searchScore = queryInfo[i].score; // 찾을 점수
        // 찾을 점수를 기준으로 이진 탐색
        int startIndex = lower_bound(sortedApplicantScore.begin(),sortedApplicantScore.end(), make_pair(searchScore, 0), comp) 
                            - sortedApplicantScore.begin();

    
        int count = 0; // 매칭되는 지원자 수
        // 매칭되는 점수 이상의 점수를 가진 지원자부터 오른쪽으로 계속 매칭 확인 함(오름차순으로 정렬을 했기 때문에)
        for(int j = startIndex; j < sortedApplicantScore.size(); j++){
            int index = sortedApplicantScore[j].second;

            if(queryInfo[i].language != "-"){
                if(queryInfo[i].language != applicantInfo[index].language){
                    continue;
                }
            }
            if(queryInfo[i].position != "-"){
                if(queryInfo[i].position != applicantInfo[index].position){
                    continue;
                }
            }
            if(queryInfo[i].experince != "-"){
                if(queryInfo[i].experince != applicantInfo[index].experince){
                    continue;
                }
            }
            if(queryInfo[i].food != "-"){
                if(queryInfo[i].food != applicantInfo[index].food){
                    continue;
                }
            }
            count++; // 매칭 되면 지원자수 증가
        }

        answer.push_back(count);
    }

    return answer; 
}

/*
int main(void){
    vector<string> info;
    info.push_back("java backend junior pizza 150");
    info.push_back("python frontend senior chicken 210");
    info.push_back("python frontend senior chicken 150");
    info.push_back("cpp backend senior pizza 260");
    info.push_back("java backend junior chicken 80");
    info.push_back("python backend senior chicken 50");

    vector<string> query;
    query.push_back("java and backend and junior and pizza 100");
    query.push_back("python and frontend and senior and chicken 200");
    query.push_back("cpp and - and senior and pizza 250");
    query.push_back("- and backend and senior and - 150");
    query.push_back("- and - and - and chicken 100");
    query.push_back("- and - and - and - 150");

    vector<int> result = solution(info, query);
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<' ';
    }
}
*/
