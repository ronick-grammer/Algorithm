//problem link: https://www.acmicpc.net/problem/1026
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int n;
int a[50], b[50];

int compare(int a, int b){
    return a > b;
}

int main(void){
    cin >> n;

    for(int i = 0; i < n; i++){
        scanf(" %d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        scanf(" %d", &b[i]);
    }

    // A의 가장 작은 수와 B의 가장 작은 수를 차례차례 곱하여 더해주면 된다.
    sort(a, a + n);
    sort(b, b + n, compare);
    
    int result = 0;
    for(int i = 0; i < n; i++){
        result += (a[i] * b[i]);
    }

    cout<<result<<'\n';
}
