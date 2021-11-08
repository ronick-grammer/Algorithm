//problem link: https://programmers.co.kr/learn/courses/30/lessons/12915
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int index;

bool compare(string a, string b) {
    // 같으면 사전순으로 앞선 문자열이 앞으로 오도록
    if(a[index] == b[index]) {
        return a < b;
    }
    
    return a[index] < b[index];
}

vector<string> solution(vector<string> strings, int n) {
    index = n;
    
    // 정렬
    sort(strings.begin(), strings.end(), compare);
    
    return strings;
}
