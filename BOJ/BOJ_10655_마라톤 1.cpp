#include <iostream>
#include <algorithm>
using namespace std;

//problem link: https://www.acmicpc.net/problem/10655

int arr[100001][2];

int main(void){
  int n;

  cin >> n;
  
  int sum = 0;
  for(int i = 1; i <= n; i++){
    int row, column;
    cin >> row >> column;

    arr[i][0] = row;
    arr[i][1] = column;

    if(i > 1){
      // 체크포인트 -> 다음 체크포인트로 가는 비용을 차례로 더해준다
     sum += abs(arr[i-1][0] - arr[i][0]) + abs(arr[i-1][1] - arr[i][1]); 
    }
  }

  int minSum = 1e9;
  for(int i = 2; i < n; i++){
    int sub_sum = sum;

    int checkPoint_skip = abs(arr[i - 1][0] - arr[i][0]) + abs(arr[i - 1][1] - arr[i][1]);
    checkPoint_skip += (abs(arr[i + 1][0] - arr[i][0]) + abs(arr[i+1][1] - arr[i][1]) );
    
    int checkPoint_reroute = abs(arr[i - 1][0] - arr[i + 1][0]) + abs(arr[i - 1][1] - arr[i + 1][1]);

    sub_sum -= checkPoint_skip; // 현재 체크포인트와 연결된 전 체크포인트와 다음 체크포인트의 비용을 빼주고
    sub_sum += checkPoint_reroute; // 전 체크포인트와 다음 체크포인트를 연결시킨 비용을 더해준다

    minSum = min(minSum, sub_sum);
  }

  cout<<minSum<<'\n';
}
