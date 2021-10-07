// problem link: https://www.acmicpc.net/problem/2302
#include <iostream>
using namespace std;

long long dp[40];
int result = 1;

int main(void){
    int n, m;
    cin>>n;
    cin>>m;

    int startSeat = 2;
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 0; i < m; i++) {
        int fixedSeat; // 고정석 
        scanf("%d", &fixedSeat);

        // startSeat 부터 fixedSeat 까지 부분적으로 만들수 있는 좌석의 가짓수
        for(int j = startSeat; j < fixedSeat; j++) {
            dp[j] = dp[j - 2] + dp[j - 1];
        }
        
        result *= dp[fixedSeat - 1]; // 그 가짓수를 각각 곱하면 사람들이 좌석에 앉을 수 있는 방법의 가짓수를 알아낼 수 있다.

        dp[fixedSeat] = 1;  // dp[i] = dp[i-2] + do[i-1] 이기에, 여기서 부터는 dp[startSeat] 는 1부터 시작함
        dp[fixedSeat - 1] = 0;
        startSeat = fixedSeat + 1; // 고정석 다음 좌석부터 다시 가능한 부분 좌석 가짓수를 구한다.
    }

    // 마지막으로 남은 좌석들을 처리해주기
    for(int i = startSeat; i <= n; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    cout<<result * dp[n]<<'\n';
}
