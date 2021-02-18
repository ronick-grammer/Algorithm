#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

//problem link: https://www.acmicpc.net/problem/14501

pair<int, int> schedule[16];
int dp[16];
int maxValue;

int main(void){
    int n;

    cin>>n;
    for(int i = 1; i <= n; i++){
        int t, p;
        cin >> t >> p;
        schedule[i] = make_pair(t, p);
    }

    for(int i = n; i >= 1; i--){ // schedule[n] 상담시간이 하루가 걸릴 경우도 처리해줘야 한다(n + 1 일까지 상담은 끝낼수 있으므로)
        int time = i + schedule[i].first;

        if(time <= n + 1){ // n + 1 일 까지 상담을 끝낼 수 있다면
            // 현재 최대 비용 = max(현재 비용 + 상담이 끝난 날 당시의 최대 비용, 지금까지의 최대 비용)
            // dp(i) = max(p(i) + dp(i + t(i)), dp(i+1))
            dp[i] = max(schedule[i].second + dp[time], dp[i+1]);
        }else{ // 상담기간을 초과하면 지금까지의 최대 상담비용을 저장
            dp[i] = dp[i+1];
        }
    }

    cout<<dp[1]<<'\n';
}
