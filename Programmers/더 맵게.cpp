//problem link: https://programmers.co.kr/learn/courses/30/lessons/42626
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    
    // 우선순위 큐를 이용하여 정렬
    for(int i = 0; i < scoville.size(); i++) {
        pq.push(-scoville[i]);
    }
    
    int sum = 0;
    // 음식이 최소 두개 이하거나, 모든 음식들의 스코빌 지수가 K 보다 높으면 빠져나오기
    while(pq.size() >= 2 && -pq.top() < K) {
        
        // 우선 섞을 음식 두개를 가져오기
        int v1 = -pq.top();
        pq.pop();
        int v2 = -pq.top();
        pq.pop();
        
        // 음식 두개를 섞기
        sum = v1 + (v2 * 2);
        pq.push(-sum);
        
        answer++;
    }
    
    // 남아있는 가장 낮은 스코빌 지수가 K보다 낮으면 모든 음식의 스코빌 지수가 높은게 아니므로 실패
    if(-pq.top() < K) return -1;
    
    return answer;
}
