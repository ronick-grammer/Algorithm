//problem link: https://www.acmicpc.net/problem/2512
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
int result;

void binarySearch(int left, int right){
    if(left > right) return;
    
    int mid = (left + right) / 2;

    // n이 최대 10,000 각 n의 값은 최대 100,000 이므로
    // 최대 10,000 * 100,000 의 값이 나올 수 있다. 최대 정수형으로 잡아준다.
    long long sum = 0; 
    for(int i = 0; i < v.size(); i++){
        if(v[i] > mid) // 상한액 이상이면 
            sum += mid; // 상한액을 더해준다.
        else
            sum += v[i];
    }
    
    if(sum > m){ // 총 예산 이상이면 줄여야 한다.
        binarySearch(left, mid - 1);
    }
    else{ // 총 예산 이하이면 늘려야 한다.
        result = max(result, mid);
        binarySearch(mid + 1, right);
    }
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        scanf(" %d", &x);
        v.push_back(x);
    }
    cin >> m;
    
    sort(v.begin(), v.end());
    binarySearch(0, v.back()); // 가장 최소 값과 최대 값이 같을 수 있다. 같을 경우에는 오답이 나오므로 최소 값을 0으로 설정해준다.
    cout<<result<<'\n';
}
