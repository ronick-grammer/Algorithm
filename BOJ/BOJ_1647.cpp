#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// 크루스칼 알고리즘으로 최소 신장 트리로 만들고 그중에서 가장 유지비가 큰 간선을 없애면
// 두 마을로 쪼개지고 두 마을의 최소 유지비 합을 구한다

int n, m; // n: 집의 갯수, m: 길의 갯수
vector< pair<int, pair<int, int> > > path; // a - b 연결하는 길의 유지비 c
int parent[100001];

int findParent(int x){ 
    if(parent[x] == x){
        return x;
    }
    else{
        return parent[x] = findParent(parent[x]);
    }
}

void unionParent(int a, int b){
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
    int result = 0, max_path = 0; // result : 최소 유지비의 합, max_path: 최소 신장트리중에서 가장 큰 유지비

    cin>> n >> m;

    for(int i = 1; i <= n; i++){ // 우선 자기 자신을 가르키게 한다
        parent[i] = i;
    }

    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;

        path.push_back(make_pair(cost, make_pair(a, b)));
    }

    sort(path.begin(), path.end()); // 유지비를 기준으로 오름차순 정렬

    for(int i = 0; i < m; i++){  // 크루스칼 알고리즘 수행
        int a = path[i].second.first;
        int b = path[i].second.second;

        if(findParent(a) != findParent(b)){ // 사이클을 이루지 않으면
            unionParent(a, b); // 두 집을 연결하고(최소 신장 트리를 만든다)
            result += path[i].first;  // 그 유지비용을 계속 합쳐준다

            max_path = max(max_path, path[i].first); // 최소 신장 트리에서 유지비가 가장 큰 걸 저장해준다
        }
    }

    cout<<result - max_path <<endl; // 최소신장트리에서 그 중 유지비가 가장 큰 액수를 빼준다 == 두개의 마을로 나눈 유지비의 최소 총 액
}
