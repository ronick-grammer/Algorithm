//problem link: https://www.acmicpc.net/problem/1427
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std;

int main(void) {
    string s;
    cin>>s;

    vector<int> v;
    for(int i = 0; i < s.size(); i++) {
        v.push_back(s[i] - '0');
    }
    sort(v.begin(), v.end(), greater<>());
    
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i];
    }
}
