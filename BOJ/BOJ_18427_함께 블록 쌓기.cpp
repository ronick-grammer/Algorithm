#include <iostream>
#include <vector>
using namespace std;

//problem link: https://www.acmicpc.net/problem/18427

int n, m, h;
vector<int> blocks[51];
int dp[51][1001];

int main(void){
    cin >> n >> m >> h;

    for(int i = 1; i <= n; i++){
       while(1){
            int x;
            cin >> x;
            blocks[i].push_back(x);

            if(cin.get() == '\n')
                break;
        }
    }

    for(int i = 0; i <= n; i++){
        dp[i][0] = 1; // 초기값
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= h; j++){
            for(int k = 0; k < blocks[i].size(); k++){
                if(j >= blocks[i][k]){
                    // 현재 학생이 가진 블록의 높이 block[i][k]와 현재까지의 j - block[i][k] 높이가 더해졋을 때,
                    // j 를 만들수 있는 경우의 수를 더해준다.
                    // ex) 만들고자 하는 높이: 5, 학생의 블록: 2 일때, j - block[i][k] = 3
                    dp[i][j] += dp[i - 1][j - blocks[i][k]];
                    dp[i][j] %= 10007;
                }
            }
            dp[i][j] += dp[i - 1][j] ; // 그리고 지금까지 만들수 있는 높이 j의 경우의 수를 더해준다.
            dp[i][j] %= 10007;
        }
    }
    cout<<dp[n][h]<<'\n';
}
