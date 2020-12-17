#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define IMPOSSIBLE 999999 // 불가능을 의미

int n, m; // 화폐 코인의 갯수: n, 만들고자 하는 화폐: m
vector<int> arr; // 화폐 코인들을 담을 변수


int main(void){
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    vector<int> dp(m+1, IMPOSSIBLE); // 특정 화폐를 만드는 게 불가능한 경우로 초기화
    dp[0] = 0; // 특정 화폐를 만들기 위해 하나씩 +1 을 하기 위해

    for(int i = 0; i < n; i++){  
        int current_coin = arr[i]; // 현재 화폐코인
        
        // 각 현재 '화폐코인'이 만들수 있는 경우의 수를 '만들고자하는 화폐'까지 하나씩 증가시키면서 전부 기록한다.
        for(int j = current_coin; j <= m; j++){  

            // 화폐코인으로 특정화폐를 만들수 있다면, ex) curret_coin:'3'은 j:'4' or '5'를 못만든다. 
            // 그러나, current_coin:'3'은 j:'3' or '6' 등을 만들수 있다.
            if(dp[j-current_coin] != IMPOSSIBLE){ 
                dp[j] = min(dp[j] ,dp[j-current_coin] + 1); // 이미 기록되어 있는 경우를 대비해, 최소 경우의 수를 기록한다.
            }
        }
    }

    if(dp[m] == IMPOSSIBLE){
        cout<<"-1"<<endl;
    }
    else{
        cout<<dp[m]<<endl;
    }
}
