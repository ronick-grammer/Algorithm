#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 이진탐색으로 풀수 있는 문제이지만 생각나는 대로 풀어보았다.
// 구현은 이진탐색을 했을때보다 간단하고 코드도 짧아졌지만
// m의 값이 매우 크다면 속도는 시간복잡도 logN 인 이진탐색에 비해 느릴것이다. 


int n, m; // n: 떡의 갯수, m : 가져가고자 하는 떡의 길이
vector<int> v;

int GetHeight(int max, int target){
    int sum = 0;
    int height = max; // 길이가 가장 큰 떡의 길이를 절단기의 높이로 최초 설정해준다

    while(sum < target){ // 절단기로 자르고 남은 떡들의 합이 목표로 하는 떡의 길이와 같거나 혹은 넘을때 까지 진행
        sum = 0;
        height--; // 절단기 높이를 한단계씩 낮춰준다. 절단기 높이를 낮춘다는 것은 자르고 남은 떡들의 길이 합이 커진다는 것을 의미한다.
        for(int i = 0; i < n; i++){ // 가지고 있는 떡들의 갯수만큼 진행하고
            if(v[i] - height > 0) // 음수는 합하지 않는다(절단기 높이보다 떡의 길이가 같거나 낮은 경우이다)
                sum += v[i] - height; // 떡들을 절단기로 잘라 남은 떡들의 길이 합을 구한다. 
        }
    }
    return height; // 절단기 높이 반환
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end()); // 가지고 있는 떡들 중 길이가 가장 큰 떡의 길이를 찾기 위해 정렬
    cout<<GetHeight(v[n-1], m)<<endl;
}
