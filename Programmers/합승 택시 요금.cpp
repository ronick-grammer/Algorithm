#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e9
int dp[201][201];

//problem link: https://programmers.co.kr/learn/courses/30/lessons/72413

int solution(int n, int s, int a, int b, vector<vector<int> > fares) {
    int answer = INF;

    for(int i = 1; i <= n; i++){
        fill_n(dp[i], n + 1, INF); // 어느 지점과도 연결되어있지 않다는 의미로 무제한 값으로 초기화
        dp[i][i] = 0;
    }

    // 플로이드를 위해 충분히 큰 값으로 초기화
    for(int i = 0; i < fares.size(); i++){ // 양방향 비용으로 초기화
        dp[fares[i][0]][fares[i][1]] = fares[i][2];
        dp[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    // 플로이드 와샬알고리즘으로 모든 각 간선으로 다른 모든 간선으로 가는 최소비용을 구함
    for(int through = 1; through <= n; through++){
        for(int from = 1; from <= n; from++){
            for(int to = 1; to <= n; to++){
                // abs 함수 사용 이유 : 오버플로 발생시 음수 값으로 변할 경우때문에
                dp[from][to] = min(dp[from][to], abs(dp[from][through] + dp[through][to]));
            }
        }
    }
    
    // 그리고 (출발지점(s)->다른지점(i)) + (다른지점(i)->A지점) +  (다른 지점(i)->B지점)
    // 중에서 가장 최소값을 구함
    for(int i = 1; i <= n; i++){
        answer = min(answer, abs(dp[s][i] + dp[i][a] + dp[i][b])); // abs 함수 사용 이유 : 오버플로 발생시 음수 값으로 변할 경우때문에
    }

    return answer;
}
