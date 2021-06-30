//problem link: https://www.acmicpc.net/problem/10867
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    int n;
    vector<int> v;

    cin>>n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end()); // 오름차순 정렬
    
    cout<<v[0]<<' ';
    for(int i = 1; i < v.size(); i++){ // 중복 제거
        if(v[i-1] != v[i])
            cout<<v[i]<<' ';
    }
}
