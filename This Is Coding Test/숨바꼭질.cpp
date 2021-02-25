#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 1e9

int n, m;

int d[20001]; // 최단 거리 저장
vector<pair<int, int> > graph[20001]; // 헛간번호, 거리

pair<int, pair<int, int> > result; // 최단 거리가 가장 먼 헛간 번호, 그 헛간까지의 거리, 최단 거리가 가장 먼 헛간과 같은 거리를 가지는 헛간 갯수

void dijkstra(int start){
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    d[start] = 0; // 출발지점은 0의 거리

    while(!pq.empty()){
        int current_cost = -pq.top().first;
        int current_number = pq.top().second;
        pq.pop();

        if(d[current_number] < current_cost){ // 처리된 적 있으면 무시
            continue;
        }

        for(int i = 0; i < graph[current_number].size(); i++){
            int next_number = graph[current_number][i].first;
            int next_cost = current_cost + graph[current_number][i].second;

            if(d[next_number] > next_cost){
                d[next_number] = next_cost;
                pq.push(make_pair(-next_cost, next_number));
            }
        }
    }

    int cost = d[1]; // 최단 거리가 가장 먼 헛간의 거리
    int max_minNumber = 1; // 최단 거리가 가장 먼 헛간 번호
    for(int i = 2; i <= n; i++){ // 2 번 헛간부터 비교 시작
        if(cost == d[i]){ // 거리가 같다면
            if(max_minNumber > i){  // 헛간 번호가 낮은게 우선
                max_minNumber = i;
            }
        }
        else if(cost < d[i]){ // 최단 거리가 가장 먼 거리와 헛간 번호를 저장해준다
            cost = d[i]; 
            max_minNumber = i;
        }
    }
    
    // 이진 탐색을 이용해 최단 거리가 가장 먼 헛간과 같은 거리를 가지는 헛간 갯수를 구하자
    sort(d, d + n + 1);     
    int* left = lower_bound(d, d + n + 1, cost);
    int* right = upper_bound(d, d + n + 1, cost);
    int sames = right - left;

    result = make_pair(max_minNumber, make_pair(cost, sames));
}

int main(void){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;

        // 양방향을 가지게 저장
        graph[from].push_back(make_pair(to, 1)); 
        graph[to].push_back(make_pair(from, 1));
    }

    fill(d, d + n  + 1, INF);

    dijkstra(1); // 1번 헛간
    cout<<result.first<<' '<<result.second.first<<' '<<result.second.second<<'\n';
}
