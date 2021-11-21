//problem link: https://programmers.co.kr/learn/courses/30/lessons/42577
#include <string>
#include <vector>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) {
    
    map<string, bool> duplicatedList;
    
    // 모두 중복처리
    for(int i = 0; i < phone_book.size(); i++) {
        duplicatedList[phone_book[i]] = true;
    }
    
    
    for(int i = 0; i < phone_book.size(); i++) {
        string s = "";
        // 자기 자신은 제외시켜야 하므로 size - 1 을 해서 마지막 문자는 추가안되게 함
        for(int j = 0; j < phone_book[i].size() - 1; j++) {
            //문자하나씩 추가해주면서 중복되어있는지 확인
            s += phone_book[i][j];
            if(duplicatedList[s]) return false;
        }
    }
    
    return true;
}
