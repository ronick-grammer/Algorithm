#include <iostream>
using namespace std;

//problem link: https://www.acmicpc.net/problem/1965

int n;
int box[1001];
int dp[1001];
int result;

int main(void){
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> box[i];
        dp[i] = 1;
    }
   
    for(int i = 2; i <= n; i++){ // 현재 i 상자에 
        for(int j = i-1; j >= 1; j--){ // 들어 갈수 있는 상자의 수를 아래부터 차례로 확인
            if(box[i] > box[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]); 
    }

    cout<<result<<'\n';
}
