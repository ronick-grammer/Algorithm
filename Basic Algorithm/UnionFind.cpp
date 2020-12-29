#include <iostream>
using namespace std;

int v, e; // v: 요소 갯수, e : 집합 갯수
int parent[100001]; // 각 요소의 루트를 저장할 변수

int findParent(int x){
    if(x == parent[x]){ // 루트 노드이면 루트노드 반환
        return x;
    }
    else{
        // DP 의 memoization 같은 느낌. 이로 인해 기존 시간복잡도 O(v*m) 이 개선된다
        // m : find 혹은 union 연산의 수 
        return parent[x] = findParent(parent[x]); // 경로 압축 기법(Path Compression)
        
        //return findParent(parent[x]); // O(v*e)
    }
}

void unionParent(int a, int b){
    int parent_a = findParent(a); // a가 가르키고 있는 루트를 찾는다
    int parent_b = findParent(b); // b가 가르키고 있는 루트를 찾는다

    if(parent_a > parent_b){ // 더 작은게 부모 값이 된다
        parent[parent_a] = parent_b;
    }
    else{
        parent[parent_b] = parent_a;
    }
}

int main(void){
    cin >> v >> e;
    
    for(int i = 1; i <= v; i++){ // 합집합을 찾을 때에는 처음에 자기 자신을 가르키도록 한다.
        parent[i] = i; 
    }

    for(int i = 0; i < e; i++){ // 각 집합 입력
        int a, b;
        cin >> a >> b;

        unionParent(a, b);  // 합집합 진행
    }

    cout<<"각 원소가 속한 집합: ";
    for(int i = 1; i <= v; i++){
        cout<<findParent(i)<<" "; // 여기서 부모노드가 다시 재설정 
    }
    cout<<endl;

    cout<<"부모 테이블: ";
    for(int i = 1; i <= v; i++){
        cout<<parent[i]<<" ";
    }
}
