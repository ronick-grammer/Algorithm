//problem link: https://programmers.co.kr/learn/courses/30/lessons/42586#qna
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    // 작업이 끝나는 일 수 계산
    for(int i = 0; i < progresses.size(); i++){
        int a = 100 - progresses[i];
        int b = a / speeds[i];
        if(a % speeds[i] != 0){ // 나머지가 있으면 하루를 더 더한다
            q.push(b + 1);
        } else {
            q.push(b);
        }
    }

    int count = 1; // 배포될 기능 갯수
    int x = q.front(); // 첫 기능 작업 일 수
    q.pop();
    while(!q.empty()){
        if(x < q.front()) { // 앞선 기능(들)이 끝나고 현재 기능 작업이 아직 안끝났다면
            answer.push_back(count); // 그 기능(들)은 배포하고
            x = q.front(); // 현재 기능 작업이 끝나는 일 수를 넣어준다. 
            count = 1; // 그리고 다시 카운트
        } else { // 앞선 기능 작업이 아직 안끝나고 현재 기능 작업이 끝났으면 
            count++; // 기다린다(배포일을 앞선 기능 작업이 끝날때 까지 미룬다)
        }
        q.pop();
    }
    answer.push_back(count); // 마지막 기등들을 배포한다.
    
    return answer;
}
