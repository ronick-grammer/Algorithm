#include <iostream>
using namespace std;

int plane[100001];
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
    int g, p;

    cin>>g;
    cin>>p;

    for(int i = 0; i <= g; i++){
        parent[i] = i;
    }
    
    for(int i = 1; i <= p; i++){
        int x;
        cin >> x;
        
        plane[i] = x;
    }

    int result = 0;
    for(int i = 1; i <= p; i++){
        int x = plane[i]; // 비행기의 루트 확인
        if(parent[x] == 0){ // 비행기의 루트가 0 이라면 (더이상 더이상 탑승구에 도킹할수 없다면)
            break; // 종료
        } 
        
        //  --- 비행기의 루트가 0이 아니라면, 1 ~ plane[i] 까지의 탑승구 번호 중에서 도킹이 되지 않은 가장 높은 번호의 탑승구와 도킹하는 것이 문제의 핵심 ---
        // 그러고 나서 합집합을 수행해서 도킹된 탑승구의 번호를 처리하고(도킹되었으므로) 그 아래 번호의 탑승구를 처리하게 하자.
        // 예를 들어 5번 탑승구가 도킹되었다면 5번 탑승구는 더이상 도킹될 수가 없으므로 5번 탑승구에 5번 이상의 탑승구 번호를 가진 비행기가 또 와서 
        // 도킹을 시도 한다면 안되지 않나? 그렇기에 5번 탑승구는 본인은 이미 자리가 다 찼으니 그 아래 번호의 탑승구로 가서 자리를 찾아보라고 말하게 해야한다.
        // 그렇게 계속 빈 탑승구를 찾아 아래 번호의 탑승구로 가고 가다가 결국 없다면 0 을 만나게 될것이다.
        // 참고로 n번의 탑승구 번호를 가진 비행기는 1 ~ n번 까지의 탑승구 중 하나와 도킹을 할 수가 있다.
        unionParent(parent[x], parent[x] - 1); 
        result++;
    }

    cout<<result<<'\n';
}
