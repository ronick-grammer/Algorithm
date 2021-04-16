#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//problem link: https://www.acmicpc.net/problem/3079

// 입력으로 주어지는 값들이 최대 10억이기에 int형이 아닌 long long 형으로 다룬다
long long n, m;
vector<int> time_judge;
long long result;

long long binarySearch(long long left, long long right){
  long long seconds;
  
  while(left <= right){
    long long mid = (left + right) / 2; 
    long long sum = 0;
    
    // 이분 탐색한 초 동안 각 심사관들이 심사할 수 있는 인원들의 총합을 구한다.
    for(int i = 0; i < n; i++){
      sum += (mid / time_judge[i]); 
    }
    
    // 그리고 그 인원들의 총합이 실제 인원보다 같거나 많다면 
    // 이분 탐색한 초 동안 심사가 이루어 질 수 있다는 의미이므로 그 초를 저장한다.
    // 그리고 이분 탐색한 초의 범위를 또 반(이분)으로 줄여서 최소 시간을 찾아야한다.
    if(sum >= m){
      right = mid - 1; 
      seconds = mid; 
    }
    // 인원들의 총합이 실제 인원보다 적다면
    // 이분 탐색한 초 동안 심사가 이루어 질 수 없다는 의미이므르 이분 탐색할 초를 늘려야 한다.
    else{
      left = mid + 1;
    }
  }

  return seconds;
}

int main(void){
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    time_judge.push_back(x);
  }

  sort(time_judge.begin(), time_judge.end());
  
  // 최소 시간을 구하는 것이기에, 최소 시간 1과 최대 시간 사이에서 최소 시간을 탐색한다
  result = binarySearch(1, time_judge[n - 1] * m);
  cout<<result<<'\n';
}
