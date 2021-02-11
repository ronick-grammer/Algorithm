#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int binarySearch(int start, int end){
    if(start > end){ // 여기까지 왔다는 건 고정점이 없다는 것
        return -1;
    }

    int mid = (start + end) / 2;

    if(v[mid] > mid){ // 중간점의 값보다 중간점이 작은 경우 왼쪽 탐색
        return binarySearch(start, mid - 1);
    }
    else if(v[mid] < mid){ // 중간점의 값보다 중간점이 큰 경우 오른쪽 탐색
        return binarySearch(mid + 1, end);
    }
    else{ // 같으면 값 반환
        return mid;
    }
}

int main(void){
    int n;
    cin>>n;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout<<binarySearch(0, n - 1)<<'\n';
}
