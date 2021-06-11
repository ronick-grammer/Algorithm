//problem link: https://www.acmicpc.net/problem/1181
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<string> strs;

bool compare(string a, string b){
    if(a.size() == b.size())
        return a < b;

    return a.size() < b.size();
}

int main(void){
    cin>>n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        strs.push_back(s);
    }

    sort(strs.begin(), strs.end(), compare);

    vector<string> result;
    result.push_back(strs[0]);
    for(int i = 1; i < n; i++){
        if(result.back() != strs[i]){ // 중복 단어 제거
            result.push_back(strs[i]);
        }
    }
    
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<'\n';
    }
}
