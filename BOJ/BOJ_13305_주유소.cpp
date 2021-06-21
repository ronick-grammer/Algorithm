#include <iostream>
#include <algorithm>
using namespace std;

int n;
int road[100000];
int gasCost[100001];

int main(void){
    cin>>n;

    for(int i = 1; i <= n - 1; i++){
        scanf(" %d", &road[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf(" %d", &gasCost[i]);
    }

    // 첫 지점에서 두 번째 지점까지 갈 때, 최소한 두 지점 사이의 거리만큼 기름을 첫 지점에서 채워주어야 한다.
    long long min_cost = 1e9;
    long long result = 0; // 주유소당 기름 가격이 10억 까지이므로 이를 계속 더하면 int 형의 범위를 초과한다. 그러므로 long long 형으로 선언
    for(int i = 1; i < n; i++){
        // 주유소를 계속 돌면서 가장 낮은 기름 비용을 갱신해준다.
        if(min_cost > gasCost[i])
            min_cost = gasCost[i];
        result += (min_cost * road[i]);
    }

    cout<<result<<'\n';
}
