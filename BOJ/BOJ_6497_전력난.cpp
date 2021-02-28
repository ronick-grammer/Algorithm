#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int parent[200001];

bool compare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    return a.second.second < b.second.second;
}

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

    while(1){
        int n, m;
        vector<pair<int, pair<int, int> > > graph; 

        cin >> n >> m;
        
        if(n == 0 && m == 0){
            break;
        }

        for(int i = 0; i < m; i++){
            int a, b, cost;
            cin >> a >> b >> cost;

            graph.push_back(make_pair(a, make_pair(b, cost)));
        }
        for(int i = 0; i < n; i++){
            parent[i] = i; // 자기 자신에 속하도록 초기화
        }

        sort(graph.begin(), graph.end(), compare); // 최소 비용만으로 그래프를 이루기 위하여 정렬

        // 크루스칼 알고리즘 ㄱㄱ
        int result = 0;
        for(int i = 0; i < m; i++){
            int a = graph[i].first;
            int b = graph[i].second.first;
            int cost = graph[i].second.second;

            // 아낄 수 있는 최대 금액 구하기
            if(findParent(a) == findParent(b)){ // 두 마을이 이미 같은 그룹이라면(사이클을 이룬다면) 그 비용을 더해준다
                result += cost;
            }
            else{
                unionParent(a, b); // 그게 아니면 두 마을을 하나의 그룹으로 합친다
            }
        }

        fill_n(parent, n, 0);
        cout<<result<<'\n';
    }
}
