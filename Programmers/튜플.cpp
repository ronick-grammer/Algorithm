//problem link: https://programmers.co.kr/learn/courses/30/lessons/64065
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool elements[100001];

bool compare(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int> > tuples; 
    vector<int> tuple;
    
    int pos = 2; // 첫 튜플의 첫 원소부터 시작
    for(int i = 2; i < s.size() - 1; i++) {
        if(s[i] == ',') {
            tuple.push_back(stoi(s.substr(pos, i - pos)));
            pos = i + 1;
        } else if(s[i] == '}') {
            tuple.push_back(stoi(s.substr(pos, i - pos)));
            pos = i + 3; // 바로 다음 튜플 원소부터 시작
            
            tuples.push_back(tuple);
            tuple.clear();
            i += 2; // 다음 튜플로 점프(반복문 돌면서 + 1되기에 2만 더해줌)
        }
    }
    
    // 원소 갯수기준 오름차순으로 정렬
    sort(tuples.begin(), tuples.end(), compare);
    for(int i = 0; i < tuples.size(); i++) {
        
        for(int j = 0; j < tuples[i].size(); j++) {
            int element = tuples[i][j];
            // 중복되지 않은 튜플 원소만 차례로 추가
            if(!elements[element]) { 
                answer.push_back(element);
                elements[element] = true; // 중복 처리
                
                break; // 각 튜플은 중복되지 않은 유일한 원소를 보유
            }
        }
        
    }
    
    return answer;
}
