#include <iostream>
#include <vector>
using namespace std;

//problem link: https://www.acmicpc.net/problem/1976

int map[501][501];
int parent[501];

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
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            map[i][j] = x;
        }
    }
    
    vector<int> v;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for(int i = 1; i <= n; i++){
        parent[i] = i; // 처음에는 자기 자신을 가르킨다
    }

    // union 연산 실행
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(map[i][j] != 0){
                if(findParent(i) != findParent(j)){
                    unionParent(i, j);
                }
            }
        }
    }


    // 여행 계획에 있는 나라가 전부 연결되어 있는지 확인한다
    int first_parent = findParent(v[0]);
    bool possible = true;
    for(int i = 1; i < m; i++){
        int next_parent = findParent(v[i]);

        if(first_parent != next_parent){ // 하나의 나라라도 연결되어 있지 않다면 
            possible = false; // 여행 계획은 가능하지 않다
            break;
        }
    }

    if(possible){ // 여행 계획이 가능하다면
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
    }
}
