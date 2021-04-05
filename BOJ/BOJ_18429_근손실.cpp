#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

//problem link: https://www.acmicpc.net/problem/18429

int n, k;
vector<pair<int, int> > kit;

bool compare(pair<int, int> a, pair<int, int> b){
  return a.first < b.first;
}

int main(void){
  cin >> n >> k;

  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    kit.push_back(make_pair(i, x));
  }

  sort(kit.begin(), kit.end(), compare); // permutation 함수 사용을 위해 오름차순 정렬

  int result = 0;
  do{ // 모든 경우 탐색
    int sum = 500;
    for(int i = 0; i < n; i++){
      sum += (kit[i].second - k);
     
      if(sum < 500){
       break;
      }
    }

    if(sum >= 500){
      result++;
    }
  }while(next_permutation(kit.begin(), kit.end(), compare));

  cout<<result;
}
