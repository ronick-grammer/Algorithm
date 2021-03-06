#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> v1, v2; // 모든 부품의 고유번호를 담을 변수와 특정 부품의 고유번호를 담을 변수

string binarySearch(int value, int start, int end){ 
    // '=' 까지 꼭 해주어야 한다. start 와 end 가 같다는 것은 반으로 쪼개고 또 쪼갰는데 마지막 남은 숫자가 한개라는 것이다. 이걸 해주지 않으면 그 마지막 남은 숫자와 value를 비교하지 않게 된다
    if(start <= end){ 
        int index_mid = (start + end) / 2; // 중간점 찾기
        if(v1[index_mid] > value){ // 탐색하는 값이 중간값보다 작으면
            return binarySearch(value, start, index_mid - 1); // 왼쪽에 탐색 값이 존재
        }
        else if(v1[index_mid] < value){ // 탐색하는 값이 중간값보다 크면
            return binarySearch(value, index_mid + 1, end); // 오른쪽에 탐색 값이 존재
        }
        else{ // 같으면
            return string("yes"); //yes
        }
    }
    // 찾지 못하였으면
    return string("no"); // no
}

int main(void){
    int n, m; // 고유번호들을 담을 변수
    
    cin>>n; // 가진 모든 부품의 고유번호 갯수
    for(int i = 0; i < n; i++){
        int x;
        cin >> x; // 물건의 고유번호 입력
        v1.push_back(x);
    }

    cin>>m; // 검색할 부품의 고유번호 갯수
   
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;   // 검색할 부품 고유번호 입력
        v2.push_back(x);
    }

    sort(v1.begin(), v1.end()); // 이진탐색을 진행할 것이기에 정렬을 진행

    for(int i = 0; i < m; i++){
        cout<<binarySearch(v2[i], 0, n - 1)<<" "; // 이진탐색
    }
}
