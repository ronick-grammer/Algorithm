#include <iostream>
#include <queue>
using namespace std;

// 위상정렬이란 방향 그래프의 모든 노드를 방향성에 거스르지 않도록 순서대로 나열하는 것
// 커리큘럼에서 선수과목을 고려한 학습 순서를 결정할대 많이 사용됨
// 시간 복잡도는 O(V + E) 이다. 수행을 할때 모든 간선들을 확인하면서 노드의 차수를 확인하기 

int n, m; // n: 노드 갯수, m: 간선 갯수
int inDegree[100001]; // 각 노드의 진입차수
vector<int> v[100001];  
vector<int> sorted; // 위상정렬된 변수
queue<int> q; 

void tropologySort(){ // 위상 정렬

    while(!q.empty()){ // 큐가 빌때까지 반복
        int index = q.front(); // 큐가 
        q.pop();

        for(int i = 0; i < v[index].size(); i++){ // 연결된 노드의 수만큼 반복
            int x = v[index][i]; // 노드 반환
            
            inDegree[x]--; // 해당 노드의 진입차수를 하나씩 감소시킨다
            if(inDegree[x] <= 0){  // 진입 차수가 0 이거나 보다 작으면
                q.push(x);       // 큐에 넣고
                sorted.push_back(x); // 순서대로 넣어 정렬한다
            }            
        }
    }

}

int main(void){
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++){
        int from, to;  // from 에서 to 의 방향
        cin >> from >> to;
        v[from].push_back(to);
        inDegree[to]++; // 해당 노드의 진입차수를 하나씩 증가시킨다
    }

    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0){ // 진입차수가 0인 노드들을 시작으로한다
            q.push(i);
            sorted.push_back(i);
        }
    }

    tropologySort(); // 위상 정렬 진행

    for(int i = 0; i < n; i++){
        cout<<sorted[i]<<' ';
    }
}
