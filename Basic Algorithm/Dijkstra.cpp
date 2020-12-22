#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define INF 1e9 // 무한대 값

int n, m, start; // n : 정점의 갯수, m: 간선의 갯수, start : 시작 정점
vector< pair<int, int> > graph[100001]; // 각 정점과 연결된 다른 정점들 그리고 비용을 담을 변수
bool visited[100001]; // 방문 여부
int d[100001]; // 최단 거리를 담을 변수

int getIndex_min(){ // 최단 거리가 가장 짧은 정점을 반환한다
    int index_min = 0; 

    for(int i = 1; i <= n; i++){
        if(d[i] < d[index_min] && !visited[i]){ // 방문하지 않은 정점중에 최단거리가 가장 짧은 정점 선택
            index_min = i;
        }
    }
    return index_min;
}

void dijkstra(int start){
    // 시작 정점은 비용이 0, 그리고 방문을 처리해준다
    d[start] = 0; 
    visited[start] = true; 

    // 시작 정점과 연결된 정점들의 최단 거리를 기록한다.
    for(int i = 0; i < graph[start].size(); i++){
        int index = graph[start][i].first;
        int cost = graph[start][i].second;
        d[index] = cost;
    }
    
    for(int i = 0; i < n - 1; i++){ // 시작정점을 제외한 나머지 정점의 갯수만큼 진행
        int index_min = getIndex_min(); // 다음 정점들중 최단 거리 정점 찾기
        visited[index_min] = true; // 그 정점을 방문처리
        
        for(int j = 0; j < graph[index_min].size(); j++){ // 최단 거리가 가장 짧은 정점과 연결된 정점들의 최소 비용을 구한다.
            int next_index = graph[index_min][j].first;
            int next_cost = graph[index_min][j].second;
            int cost = d[index_min] + next_cost; // 현 정점과 연결된 정점의 간선 비용을 합함

            if(!visited[next_index]){ // 방문되지 않은 정점들 중에서 
                if(cost < d[next_index]){ // 기록되어 있는 연결된 정점의 최단 거리 비용과 비교
                    d[next_index] = cost;
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
            cout<<d[i]<<" ";
        }
    }
}

