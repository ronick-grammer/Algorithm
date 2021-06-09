//problem link: https://www.acmicpc.net/problem/12865
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int n, k;
pair<int, int> obj[101];
int dp[100001];


int main(void){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int weight, value;
        scanf(" %d %d", &weight, &value);
        obj[i] = make_pair(weight, value);
    }
    
    for(int i = 1; i <= n; i++){
        // 높은 무게에서 낮은 무게순으로 구해야 같은 물건의 가치를 중복해서 더하는걸 방지할 수 있다.
        for(int j = k; j >= obj[i].first; j--){
            // j 무게의 가방 = max(j무게의 가방에 담을 수 있던 가치의 최대 총합, j무게의 가방에 현재 물건을 넣어서 얻을 수 있는 가치의 최대 총합)
            dp[j] = max(dp[j], dp[j-obj[i].first] + obj[i].second);
        }
    }

    cout<<dp[k]<<'\n';
}
