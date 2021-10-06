#include <iostream>
using namespace std;

long long dp[101];

int main(void) {
    int testCase;
    cin>>testCase;

    dp[1] = 1;
    dp[2] = 1;
    
    for(int tc = 0; tc < testCase; tc++) {
        int n;
        cin>>n;

        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-2] + dp[i-3];
        }

        cout<<dp[n]<<endl;
    }
}
