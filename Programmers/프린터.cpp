//problem link: https://programmers.co.kr/learn/courses/30/lessons/42587
#include <string>
#include <vector>
#include <utility>
#include <list>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    list<pair<int, int> > docs;
    
    //문서 중요도와 번호를 각각 저장
    for(int i = 0; i < priorities.size(); i++) {
        docs.push_back(make_pair(priorities[i], i));
    }
    
    while(!docs.empty()) {
        
        // 우선 맨앞의 문서를 빼기
        list<pair<int, int> >::iterator iter;
        pair<int, int> front = docs.front();
        docs.pop_front();
        
        bool printed = true;
        for(iter = docs.begin(); iter != docs.end(); iter++) {
            
            //남은 문서들중에서 중요도가 더 큰게 있으면 뒤에다가 넣기
            pair<int, int> priority = *iter;
            if(priority.first > front.first) {
                docs.push_back(front);
                answer--;
                // 프린트 실패 처리
                printed = false;
                break;
            }
            
        }
        
        // 프린트 되었으면서 인쇄 요청한 문서라면 빠져 나오기
        if(printed && front.second == location) break;
        
        answer++;
    }
    
    
    return answer;
}
