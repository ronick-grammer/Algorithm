//problem link: https://www.acmicpc.net/problem/11053
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];


int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf(" %d", &arr[i]);
    }

    fill(dp, dp + n, 1); // 1 로 전부 초기화

    dp[0] = 1;
    int maxlength = 1;
    for(int i = 1; i < n; i++){
        for(int j = i - 1; j >= 0; j--){
            if(arr[j] < arr[i]) // 자기 보다 낮으면 그 자리의 가장 긴 길이 + 1을 해서 가장 긴 길이를 저장해준다.
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxlength = max(maxlength, dp[i]);
    }

    cout<<maxlength<<'\n';
}
