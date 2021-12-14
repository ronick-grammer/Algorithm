//problem link: https://programmers.co.kr/learn/courses/30/lessons/12978
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector<pair<int, int> > vileages[51];
int d[51];

// 다익스트라 가보자고 그냥 다익스트라 문제임
int dijkstra(int start, int n, int k) {
    
    priority_queue<pair<int, int>> pq;
    d[start] = 0;
    pq.push(make_pair(0, start));
    
    // 1번 정점에서 다른 모든 정점으로 가는 최소 비용 구하기
    while(!pq.empty()) {
        int current = pq.top().second;
        int current_cost = -pq.top().first;
        pq.pop();
        
        // 이미 처리되었으면 스킵
        if(d[current] < current_cost) 
            continue;
        
        for(int i = 0; i < vileages[current].size(); i++) {

            int next = vileages[current][i].first;
            int next_cost = d[current] + vileages[current][i].second;
            
            // 지금까지의 최소 비용과 현재 정점과 연결된 다른 정점으로 가는 비용과 비교
            if(d[next] > next_cost) {
                pq.push(make_pair(-next_cost, next));
                d[next] = next_cost;
            }
        }
    }
    
    // K 시간내에 갈 수 있는 마을 카운트(1번 마을은 기본 포함)
    int count = 1;
    for(int i = 2; i <= n; i++) {
        if(d[i] <= k) count++;
    }
    
    return count;
}

int solution(int N, vector<vector<int> > road, int K) {

    fill(d, d + N + 1, 1e9);
    
    for(int i = 0; i < road.size(); i++) {
        int a = road[i][0];
        int b = road[i][1];
        int cost = road[i][2];
        
        vileages[a].push_back(make_pair(b, cost));
        vileages[b].push_back(make_pair(a, cost));
    }
        
    return dijkstra(1, N, K);
}
