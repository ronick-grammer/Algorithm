#include <iostream>
#include <algorithm>
using namespace std;

// 줄 세우기

int n;
int dp[201];
int children[201];
int result;

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf(" %d", &children[i]);
    }

    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++){ 
            // 이미 부분적으로 정렬이 되어 있는 최대의 학생들을 제외한 나머지 학생들을 옮겨서 정렬하는 방식이므로
            // 최장 증가 부분 수열 알고리즘인 LIS 를 진행해서 풀어주면 된다.
            if(children[i] > children[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        result = max(result, dp[i]);
    }

    cout<<n - result<<'\n';
}
