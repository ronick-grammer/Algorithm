#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

bool compare(int a, int b){
    return a > b;
}

int main(void){
    int n;
    cin>>n;

    for(int i = 1; i <= n; i++){
        scanf(" %d", &arr[i]);
    }

    // 가장 높은 무게를 들 수 있는 로프가 앞으로 오도록 내림차순 정렬
    sort(arr + 1, arr + 1 + n, compare);

    int result = 0;
    for(int i = 1; i <= n; i++){
        // 현재 로프가 들 수 있는 (무게 * i) 를 (무게 / i) 로 나누면 앞선 로프들이 나눠 들 수 있다. 
        // 왜냐하면 앞선 로프들은 현재 로프보다 무게가 같거나 높기 때문이다.  
        int current = arr[i] * i; 
        result = max(result, current);
    }

    cout<<result<<'\n';
}
