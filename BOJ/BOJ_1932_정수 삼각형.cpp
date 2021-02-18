#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//problem link: https://www.acmicpc.net/problem/1932

vector<int> dp[500];

int main(void){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            int x;
            cin >> x;
            dp[i].push_back(x);
        }
    }

    // dp(r,c) = dp(r,c) + max(dp(r+1, c), dp(r+1, c+1))
    for(int i = n - 2; i >= 0; i--){ // 맨 마지막 층의 윗층 부터 시작
        for(int j = 0; j < dp[i].size(); j++){
            int leftChild = dp[i + 1][j];
            int rightChild = dp[i + 1][j + 1];
            dp[i][j] = dp[i][j] + max(leftChild, rightChild);
        }
    }

    cout<<dp[0][0]<<'\n';
}
