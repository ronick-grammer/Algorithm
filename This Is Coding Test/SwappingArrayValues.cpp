#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 두 배열의 원소 교체
// a 배열과 b 배열이 있고, 각 배열에는 n개 만큼의 숫자가 들어간다
// k갯수만큼 a 배열의 원소와 b 배열의 원소를 교환했을 때 a 원소들의 최대 합을 구한다

int n, k;
vector<int> a, b;

bool compare(int a, int b){
    return a > b;
}

int main(void){
    int result = 0;

    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        b.push_back(x);
    }

    sort(a.begin(), a.end()); // 오름차순
    sort(b.begin(), b.end(), compare); // 내림차순

    for(int i = 0; i < k; i++){
        if(a[i] < b[i]){ // 비교하고 교환
            swap(a[i], b[i]);
        }
    }

    for(int i = 0; i < n; i++){
        result += a[i];
    }
    cout<<result<<endl;
}
