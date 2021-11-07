//problem link: https://programmers.co.kr/learn/courses/30/lessons/12916
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p_count = 0;
    int y_count = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'p' || s[i] == 'P') p_count++;
        else if(s[i] == 'y' || s[i] == 'Y') y_count++;
    }
    // 갯수가 같거나 둘다 0이라면 true 반환
    if(p_count == y_count || (p_count == 0 && y_count == 0)) {
        return true;
    }
       
    return false;
}
