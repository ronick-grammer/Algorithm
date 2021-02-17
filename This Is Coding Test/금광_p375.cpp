#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int goldMine[21][21]; // 금광
int dp[21][21]; // dp 행렬

int main(void){
    int T;
    vector<int> v;
    cin>>T;

    for(int i = 0; i < T; i++){
        int n, m;
        cin>>n >> m;
        
        for(int row = 1; row <= n; row++){
            for(int column = 1; column <= m; column++){
                int x;
                cin >> x;
                goldMine[row][column] = x;
            }
        }
        
        // 맨 처음애는 첫 번째 열의 어느 행에서든 출발할 수 있다.
        for(int row = 1; row <= n; row++){
            dp[row][1] = goldMine[row][1]; 
        }

        // 왼쪽위, 왼쪽, 왼쪽아래 값중 최대값과 현재 위치의 값을 더한다
        // dp(r, c) = original(r, c) + max(dp(r-1, c-1), dp(r, c-1), dp(r+1, c-1))
        for(int column = 2; column <= m; column++){
            for(int row = 1; row <= n; row++){
                int left, left_up, left_down;
                if(row == 1){ // 가장 위쪽은 왼쪽 위의 값이 없으므로 0을 대입
                    left_up = 0;
                }
                else{ 
                    left_up = dp[row - 1][column - 1];
                }

                if(row == n){ // 가장 아래쪽은 왼쪽 아래의 값이 없으므로 0을 대입
                    left_down = 0;
                }
                else{
                    left_down = dp[row + 1][column - 1];
                }

                left = dp[row][column - 1]; // 왼쪽 값 대입
                
                // 다시 한번
                // dp(r, c) = original(r, c) + max(dp(r-1, c-1), dp(r, c-1), dp(r+1, c-1))
                dp[row][column] = goldMine[row][column] + max(left_up, max(left, left_down));
            }
        }

        int max_gold = 0;
        // 마지막 열의 행들중에서 최대 금을 가진 갯수를 저장
        for(int row = 1; row <= n; row++){
            max_gold = max(max_gold, dp[row][m]);
        }
        v.push_back(max_gold);
    }

    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<'\n';
    }
}
