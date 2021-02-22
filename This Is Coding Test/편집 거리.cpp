#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[5001][5001]; 

int main(void){
    string strs[2];
    string A, B;

    cin>>A;
    cin>>B;

    int n = A.size();
    int m = B.size();

    for(int i = 1; i <= n; i++){ /
        dp[i][0] = i; // A 문자열의 편집 거리
    }
    for(int i = 1 ; i <= m; i++){
        dp[0][i] = i;   // B 문자열의 편집 거리
    }

    for(int i = 1; i <= n; i++){ // 편집거리별로 A 문자와 
        for(int j = 1; j <= m; j++){ // B 문자를 비교
            if(A[i-1] == B[j-1]){ // 두 문자가 같으면 
                dp[i][j] = dp[i-1][j-1]; // 왼쪽 위의 숫자를 삽입,즉 편집거리 수 변동없음
            }
            else{ // 두 문자가 다르다면 왼쪽(삽입), 위쪽(삭제), 오른쪽 위(교체) 중 가장 작은 편집거리 수 에다가 1을 더한다.
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
    }

    cout<<dp[n][m]<<'\n';
}
