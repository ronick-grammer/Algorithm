#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

// '크루스칼' 알고리즘은 '최소 신장 트리'를 구하는 알고리즘이며
// 최소 신장 트리란, 그래프가 있을때 모든 노드가 연결되어 있으면서 사이클을 형성하지 않는 신장 트리를 말한다

// a - b 의 비용 cost 를 graph 에 담는다
vector< pair < int, pair <int, int> > > graph; 
// 

int sum;    // 최소 총 비용
int parent[100001]; // 각 노드의 루트 노드를 담을 변수

int findParent(int x){ // 루트 노드를 찾는다
    if(x == parent[x]){
        return x;
    }
    else{
        return parent[x] = findParent(parent[x]);
    }
}

void unionParent(int a, int b){ // 두 노드를 연결한다
    int parent_a = findParent(a);
    int parent_b = findParent(b);

    if(parent_a < parent_b){
        parent[parent_b] = parent_a;
    }
    else{
        parent[parent_a] = parent_b;
    }
}

int main(void){
    int v, e;
    cin >> v >> e;

    for(int i = 1; i <= v; i++){ // 처음에는 자기 자신을 루트노드로 설정
        parent[i] = i;
    }

    for(int i = 0; i < e; i++){
        int a, b, cost; // a - b 의 비용 cost
        cin >> a >> b >> cost;
        graph.push_back(make_pair(cost, make_pair(a, b)));
    }

    sort(graph.begin(), graph.end()); // 오름차순으로 정렬
    
    for(int i = 0; i < e; i++){
        int a = graph[i].second.first;
        int b = graph[i].second.second;

        if(findParent(a) != findParent(b)){ // 서로 같은 루트 노드를 가지지 않으면(사이클이 형성된 것이 아니라면)
            unionParent(a, b);
            sum += graph[i].first; // 최소 비용을 더해준다
            
        }
    }

    cout<<sum<<endl;
}
