#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
#define INF 1e9 // 무한대 값

int n, m, start; // n : 정점의 갯수, m: 간선의 갯수, start : 시작 정점 
vector< pair<int, int> > graph[100001]; // 각 정점과 연결된 다른 정점들 그리고 비용을 담을 변수
bool visited[100001]; // 방문 여부
int d[100001]; // 최단 거리를 담을 변수
priority_queue< pair<int, int> > pQ; // 우선순위 큐를 이용하여 최소 간선 거리의 정점을 반환 받는다

void dijkstra(int start){
    d[start] = 0;
    pQ.push(make_pair(0, start)); // 시작 정점에서 시작해서 시작 정점으로 가는 비용은 0 이 든다

    while(!pQ.empty()){
        int index_min = pQ.top().second; // 최단 거리가 가장 짧은 정점 반환
        pQ.pop(); // 최단 거리가 짧은 정점을 처리

        visited[index_min] = true; // 방문 처리
        for(int i = 0; i < graph[index_min].size(); i++){
            int nextIndex = graph[index_min][i].first; // 다음 정점
            int nextCost = graph[index_min][i].second + d[index_min]; // 다음 정점으로 가는 간선 비용
            if(!visited[nextIndex]){ // 만약 전에 방문 된 적이 없다면 진행
                if(nextCost < d[nextIndex]){ // 기록된 최단 거리 비용보다 이번에 드는 간선 비용이 더 적다면
                    d[nextIndex] = nextCost; // 새로 기록한다.
                    pQ.push(make_pair(-nextCost, nextIndex)); // c++은 최대힙 구조이기 때문에 음수를 붙여 최소힙 구조로 만든다.
                }
            }
        }
    }
}

int main(void){
    cin >> n >> m;
    cin>>start;

    for(int i = 0; i < m; i++){
        // 'from' 정점에서 'to' 정점으로 가는 간선 비용으로 'cost' 가 든다
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }
    
    //정점들의 최소 간선 비용을 무한대로 초기화
    fill_n(d, 100001, INF);
    dijkstra(start);

    for(int i = 1; i <= n; i++){
        if(d[i] == INF){
            cout<<"INF"<<endl;
        }
        else{
            cout<<d[i]<<' ';
        }
    }
}
