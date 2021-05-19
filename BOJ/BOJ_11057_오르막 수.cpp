#include <iostream>
using namespace std;

//problem link: https://www.acmicpc.net/problem/11057

int dp[1001];
int arr[1001][10];

int main(void){
    int n;
    cin >> n;
    
    dp[1] = 10;
    for(int i = 0; i <= 9; i++){
        arr[2][i] = i+1;
        dp[2] += arr[2][i];
    }

    for(int i = 3; i <= n; i++){
        arr[i][0] = 1; // [i][0]: 길이 i 일 때, 가장 큰 수인 9가 가장 앞에 위치하여 오름차순 숫자들로로 만들 수 있는 경우의 수는 한가지 밖에 없다. 
                        // ex) i=1: 9, i=2: 99, i=3: 999
        dp[i] = 1;
        
        for(int j = 1; j <= 9; j++){
            // 길이 i일때, 길이 i-1일때 만들 수 있는 9-j 수가 가장 앞에 위치하여 오름차순 숫자 만들 수 있는 경우의 수 +  길이 i일때 만들수 있는 9-j+1 수가 가장 앞에 위치하여 오름차순 숫자들을 만들 수 있는 경우의 수
            arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % 10007;
            dp[i] = (dp[i] + arr[i][j]) % 10007;
        }
    }

    cout<<dp[n] % 10007;
}
