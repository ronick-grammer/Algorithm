#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//problem link: https://www.acmicpc.net/problem/2110
/* 문제 풀이 과정 */
// 본 문제는 매우 넓은 입력 범위가 주어지므로 O(logN) 이 걸리는 이진탐색을 진행한다
// 1. 입력된 집들을 번호순으로 정렬(Sort)한다.
// 2. 설치 간격을 정한다. 첫 설치 간격은 '1 ~ (가장 높은 번호의 집 번호 - 가장 낮은 번호의 집 번호)' 로 한다
//  2-1. 정해진 설치 간격에서 중간을 선택하여 설치 기준 간격으로 정한다.
//  2-2. 첫번째 집부터 차례로 설치 기준 간격으로 공유기를 설치한다.
// 3. 공유기를 전부 설치하였다면 설치 간격을 더 넓혀서 최대 간격을 찾는다.
// 4. 공유기를 전부 설치 하지 못하였다면 설치 간격을 줄여서 전부 설치할 수 있도록 한다.
// 5. 2-1 으로 가서 반복한다

int N, C;
vector<int> houses;

int binarySearch(int start, int end){ // 이진 탐색
    int result = -1;

    while(start <= end){
        int mid = (start + end) / 2; // 공유기 최소 설치 간격 설정
        int current_house = houses[0]; // 처음에는 첫번 째 집에 무조건 설치
        int cnt_intalled = 1; // 공유기 설치횟수

        for(int i = 1; i < houses.size(); i++){
            if(houses[i] >= current_house + mid){ // 공유기를 최소 간격마다 설치해준다
                cnt_intalled++;
                current_house = houses[i];
            }
        }

        if(cnt_intalled >= C){ // 공유기를 전부 설치했다면 간격을 더 넓혀서 설치할 수 있는지 알아보자
            result = mid; // 우선 전부 설치했으므로 그 간격을 저장해주자
            start = mid + 1;
        }
        else{   // 공유기를 전부 설치하지 못했다면 간격을 더 좁혀서 설치 가능하게 해야한다
            end = mid - 1;
        }
    }

    return result;
}

int main(void){
    cin >> N >> C;
    
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        houses.push_back(x);
    }

    sort(houses.begin(), houses.end()); // 이진 탐색을 위해 오른 차순 정렬

    // 최소 ~ 최대 간격
    cout<<binarySearch(1, houses[N - 1] - houses[0])<<'\n'; 
}
