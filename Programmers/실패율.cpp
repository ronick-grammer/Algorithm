#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

//problem link: https://programmers.co.kr/learn/courses/30/lessons/42889

int users_perStage[501];

bool compare(pair<int, double> a, pair<int, double> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double> > failures;
    int userNumber = stages.size();

    for(int i = 0; i < stages.size(); i++){
        int x = stages[i];
        users_perStage[x]++; // 스테이지별로 도달했으나 아직 클리어하지 못한 플레이어 수
    }

    for(int i = 1; i <= N; i++){
        double x = 0; // 스테이지에 도달한 유저가 없는 경우

        if(userNumber >= 1){ // 스테이지에 도달한 유저가 있는 경우
            x = (double) users_perStage[i] / userNumber;
        }
        
         failures.push_back(make_pair(i, x));

        userNumber -= users_perStage[i];
    }
    
    sort(failures.begin(), failures.end(), compare);
    for(int i = 0; i < N; i++){
        answer.push_back(failures[i].first);
    }

    return answer;
}
