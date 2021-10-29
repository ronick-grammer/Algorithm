//problem link: https://programmers.co.kr/learn/courses/30/lessons/42840
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> studentA = {1, 2, 3, 4, 5};
vector<int> studentB = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> studentC = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int resultA = 0;
    int resultB = 0; 
    int resultC = 0;
    
    for(int i = 0; i < answers.size(); i++) {
        // 패턴이니까 % 연산을 넣어서 반복 하기 
        if(studentA[i%studentA.size()] == answers[i]) resultA++;
        if(studentB[i%studentB.size()] == answers[i]) resultB++;
        if(studentC[i%studentC.size()] == answers[i]) resultC++;
    }
    
    vector< pair<int, int> > sorted;
    sorted.push_back(make_pair(1, resultA));
    sorted.push_back(make_pair(2, resultB));
    sorted.push_back(make_pair(3, resultC));
    
    // 가장 많이 맞은 정답 수 대로 정렬
    sort(sorted.begin(), sorted.end(), compare);
    
    // 가장 많이 맞은 정답 수를 가진 수포자 번호를 넣고
    answer.push_back(sorted[0].first);
    for(int i = 1; i < sorted.size(); i++) {
        // 가장 많이 맞은 정답 수가 중복일 경우 차례로 넣어줌
        if(sorted[0].second == sorted[i].second) {
            answer.push_back(sorted[i].first);
        }
    }
    
    return answer;
}
