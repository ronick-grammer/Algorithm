#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

//problem link: https://www.acmicpc.net/problem/1911

int n, l;
vector<pair<int, int> > hole;

bool compare(pair<int, int> a, pair<int, int> b){
  return a.first < b.first;
}

int main(void){
  cin >> n >> l;

  for(int i = 0; i < n; i++){
    int start, end;
    cin >> start >> end;
    hole.push_back(make_pair(start, end));
  }

  sort(hole.begin(), hole.end(), compare); // 물웅덩이의 시작 위치 기준으로 정렬

  int result = 0;
  int currentLocation = hole[0].first - 1; // 널빤지 마지막 위치
  
  for(int i = 0; i < n; i++){
    int holeSize;
    if(currentLocation >= hole[i].second){ // 널빤지가 이미 해당 웅덩이를 다 덮었으면 스킵
      continue;
    }
    // 널빤지가 해당 웅덩이에 걸쳐있다면 
    else if(currentLocation >= hole[i].first && currentLocation < hole[i].second){ 
      currentLocation++; // 설치할 위치를 한칸 옮긴후
      holeSize = hole[i].second - currentLocation; // 널빤지 설치를 위한 웅덩이 크기를 설정
    }
    else{ // 물웅덩이 전체를 덮을 널빤지 설치를 위한 물웅덩이 크기를 설정 
      currentLocation = hole[i].first;
      holeSize = hole[i].second - hole[i].first;
    }

    int need = holeSize / l; // 널빤지 갯수
    if(holeSize % l != 0){
      need++;
    }

    currentLocation += (need * l) - 1; // 널빤지가 설치된 마지막 위치 저장
    result += need; 
  }

  cout<<result<<'\n';
}
