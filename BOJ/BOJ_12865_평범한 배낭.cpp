//problem link: https://www.acmicpc.net/problem/12865
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int n, k;
pair<int, int> obj[101];
int dp[101][100001];

int main(void){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int weight, value;
        scanf(" %d %d", &weight, &value);
        obj[i] = make_pair(weight, value);
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            // j 무게의 가방에 담을 수 있는 무게라면, 
            // max(j 무게의 가방에 담을 수 있던 가치의 최대 총합, j 무게의 가방에 현재 물건을 넣어서 얻을 수 있는 최대 가치 총합)
            // dp[i-1][j-obj[i].first] 에서 dp[i-1]의 이유는 자기 자신의 가치를 중복해서 더할수 없기 때문이다.
            if(j - obj[i].first >= 0) 
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-obj[i].first] + obj[i].second);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[n][k]<<'\n';
}
