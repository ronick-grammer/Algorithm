#include <iostream>
#include <algorithm>
using namespace std;

//problem link: https://www.acmicpc.net/problem/2229

int dp[1001];
int scores[1001];
int main(void){
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        scanf(" %d", &scores[i]);
    }
     // 현재 학생 혼자서 팀인 경우부터 시작해서 뒤로 자신을 포함한 팀원의 수를 한명씩 늘려갔을 경우의 최대값을 구해준다.
     // 즉, 현재 4번 학생이라고 했을때
     // max(4번 학생 혼자 팀인 합 0, 1~3번 학생들이 팀을 여러 경우로 이뤘을 때의 최대 합)
     // max(4번 3번 학생이 팀을 이룬 경우의 합, 1~2번 학생들이 팀을 이룬 경우의 합)
     // max(4번 3번 2번 학생이 팀을 이룬 경우의 최대 합, 1번 학생 혼자 팀인 합 0)
    for(int i = 2; i <= n; i++){
        int minScore = 1e9;
        int maxScore = 0;
       
        for(int j = i; j >= 1; j--){ 
            // 현재 팀원들 중에서 가장 높은 점수와 가장 낮은 점수를 가지는 학생을 찾아야 한다.
            minScore = min(minScore, scores[j]); 
            maxScore = max(maxScore, scores[j]);
            // 그렇게 팀원들 중에서 가장 높은 점수와 가장 낮은 점수의 차이와 '직전까지' 구해진 팀들의 총 합을 더해서 최대 합을 구해 나간다 
            dp[i] = max(dp[i], maxScore - minScore + dp[j-1]);
        }
    }

    cout<<dp[n];
}
