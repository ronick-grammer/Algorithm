// problem link: https://programmers.co.kr/learn/courses/30/lessons/17681
#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<string> map1, map2;
    
    // n 자릿수 만큼의 2진수로 변환
    for(int i = 0; i < n; i++) {
        map1.push_back(bitset<16>(arr1[i]).to_string());
        map2.push_back(bitset<16>(arr2[i]).to_string());
    }
    
    for(int i = 0 ; i < n; i++) {
        string s = "";
        // 합치기
        for(int j = 16 - n; j < 16; j++) {
            if(map1[i][j] == '1' || map2[i][j] == '1') {
                s += "#";
            } else{
                s += " ";
            }
        }
        answer.push_back(s);
    }

    return answer;
}
