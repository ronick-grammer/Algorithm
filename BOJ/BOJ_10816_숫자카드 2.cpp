//problem link: https://www.acmicpc.net/problem/10816
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> first, second;

int main(void) {
    cin>>n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        first.push_back(x);
    }

    cin>>m;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        second.push_back(x);
    }

    sort(first.begin(), first.end()); // 이진 탐색을 위해 정렬
    for(int i = 0; i < m; i++) {
        // 이진 탐색으로 연속되는 숫자가 몇개있는지 찾는다.
        vector<int>::iterator left = lower_bound(first.begin(), first.end(), second[i]);
        vector<int>::iterator right = upper_bound(first.begin(), first.end(), second[i]);

        cout<<right - left<<' '; 
    }
}
