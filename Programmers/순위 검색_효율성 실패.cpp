// https://programmers.co.kr/learn/courses/30/lessons/72412
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

map<string, vector<int> > indexes;

vector<int> solution(vector<string> info, vector<string> query) {
    
    vector<int> answer;
    
    for(int i = 0; i < info.size(); i++) {
        
        vector<string> strs;
        int pos = 0;
        int current = 0;
        
        // 지원자들 정보를 종류별로 나누어 담기
        while((pos = info[i].find(' ', pos)) != string::npos) {
            strs.push_back(info[i].substr(current, pos - current));
            pos++;
            current = pos;
        }
        int score = stoi(info[i].substr(current)); //마지막 문자열은 점수

        indexes[""].push_back(score); // 쿼리가 조건 없이 점수만 요구할 수 있음
        // 검색될 수 있는 모든 경우의 조건들을 맵에 저장
        for(int i = 1; i <= strs.size(); i++) {
            
            vector<bool> visited(strs.size(), false);
            fill(visited.end() - i, visited.end(), true);
            
            do {
                
                string index = "";
                for(int j = 0; j < visited.size(); j++) {
                    if(visited[j]) {
                        index += strs[j];
                    }
                }
                
                indexes[index].push_back(score);

            } while(next_permutation(visited.begin(), visited.end()));
            
        }
        
    }
    
    for(int i = 0; i < query.size(); i++) {
        int pos = 0;
        int current = 0;
        
        string index = "";
        while((pos = query[i].find(' ', pos)) != string::npos) {
            
            string sub = query[i].substr(current, pos - current);
            if(sub != "-") index += sub;
            
            pos += 5; // 빈칸과 and 문자는 건너띔
            current = pos;
        }
        int score = stoi(query[i].substr(current - 4)); // 마지막은 점수

        int count = 0; 
        // 검색해서 조건을 만족하는 지원자 수 알아내기
        for(int j = 0; j < indexes[index].size(); j++) {
            if(indexes[index][j] >= score) count++;
        }
        answer.push_back(count);
    }
    
    return answer;
}
