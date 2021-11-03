//problem link: https://programmers.co.kr/learn/courses/30/lessons/86491
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    vector<int> length_long;
    vector<int> length_short;
    int answer = 0;
    
    for(int i = 0; i < sizes.size(); i++) {
        // 큰 것들과 작은 것들을 나누어서 저장
        if(sizes[i][0] > sizes[i][1]) {
            length_long.push_back(sizes[i][0]);
            length_short.push_back(sizes[i][1]);
        } else{
            length_long.push_back(sizes[i][1]);
            length_short.push_back(sizes[i][0]);
        }
    }
    
    // 각각 정렬뒤에 가장 큰 것을 알아내기 위해 정렬
    sort(length_long.begin(), length_long.end());
    sort(length_short.begin(), length_short.end());
    
    answer = length_long[sizes.size() - 1] * length_short[sizes.size() - 1]; 
    return answer;
}
