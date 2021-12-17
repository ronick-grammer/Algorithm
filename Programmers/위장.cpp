//problem link: https://programmers.co.kr/learn/courses/30/lessons/42578
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> map_clothes;
    
    //각 의상의 종류별로 갯수를 모두 저장
    for(int i = 0; i < clothes.size(); i++) {
        map_clothes[clothes[i][1]]++;
    }
    
    // 그리고 나서 각 의상의 조합을 구함. 
    // 해당 의상의 종류를 선택하지 않은 경우도 조합에 포함이 되므로 +1을 해줌
    map<string, int>::iterator iter;
    for(iter = map_clothes.begin(); iter != map_clothes.end(); iter++) {
        answer *= iter->second + 1;
    }
    
    // 다만 모든 의상의 종류를 선택하지 않은 경우는 없으므로 -1을 해준다.
    return answer - 1;
}
