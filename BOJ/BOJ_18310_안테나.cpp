#include <iostream>
#include <algorithm>
#include <vector>

//problem link: https://www.acmicpc.net/problem/18310

using namespace std;

int main(void){
    int n;
    vector<int> houses;
    

    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        houses.push_back(x);
    }
    
    sort(houses.begin(), houses.end());
    cout<<houses[(n - 1) / 2]<<'\n'; // 중간에 안테나 설치
}
