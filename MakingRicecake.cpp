#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; // 떡들의 갯수: n, 원하는 떡의 최소한의 높이 : m
vector<int> v; // 떡들의 높이를 담을 변수

int binarySearch(int value, int start, int end){ 
    int low = start; 
    int high = end;
    int mid;
    
    while(low <= high){
        mid = (low + high) / 2; // 절단기 높이를 설정
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            if(v[i] > mid){          
                sum += v[i] - mid; // 절단기로 잘린 '나머지' 떡들의 길이합을 구한다
            }
        }
        
        if(sum > value){ // 각 떡들을 자른 길이의 합이 더 클 경우,
            low = mid + 1; // 절단기 높이를 더 높여 자른 떡들 길이합을 더 작게 한다
        }
        else if(sum < value){ // 각 떡들을 자른 길이의 합이 더 적을 경우,
            high = mid - 1; // 절단기 높이를 더 낮추어 자른 떡들 길이합을 더 크게 한다
        }
        else{          // 각 떡들을 자른 길이의 합이 같을 경우
            return mid; // 그대로 값 리턴
        }
    }
    // '최소한 적어도 원하는 길이" 의 떡을 가져가기 위한 절단기의 높이 리턴
    //  따라서, 절단기 높이에 잘린 떡들의 길이 합 => 원하는 떡의 길이 
    return mid;
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){ // 떡들의 갯수만큼 각 떡의 길이 입력
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end()); // 떡들중 가장 길이가 큰 것을 찾기 위해 정렬

    cout<<binarySearch(m, 0, v[n-1])<<endl; // 절단기의 최대 높이는 최대 길이가 가장 긴 떡의 길이로 한다
}
