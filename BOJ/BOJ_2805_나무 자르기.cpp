//problem link: https://www.acmicpc.net/problem/2805
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int trees[1000000];

int binary_search(int left, int right){
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2; // 절단기 높이를 설정

        long long sum = 0; // 떡 길이의 합이 int형 범위를 넘어갈수 있으므로 long long
        for(int i = 0; i < n; i++){
            if(trees[i] > mid)
                sum += (trees[i] - mid); // 절단기로 잘린 '나머지' 떡들의 길이합을 구한다
        }

        if(sum >= m){ // 각 떡들을 자른 길이의 합이 같거나 더 클 경우,
            left = mid + 1; // 절단기 높이를 더 높여 자른 떡들 길이합을 더 작게 한다
            result = max(result, mid); // 절단기의 최대 높이를 저장한다.
        }
        else if(sum < m){ // 각 떡들을 자른 길이의 합이 더 적을 경우,
            right = mid - 1; // 절단기 높이를 더 낮추어 자른 떡들 길이합을 더 크게 한다
        }
    }

    return result;
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        scanf(" %d", &trees[i]);
    }

    sort(trees, trees + n);  // 떡들중 가장 길이가 큰 것을 찾기 위해 정렬

    cout<<binary_search(0, trees[n - 1]); // 절단기의 최대 높이는 최대 길이가 가장 긴 떡의 길이로 한다
}
