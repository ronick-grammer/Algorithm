//problem link: https://programmers.co.kr/learn/courses/30/lessons/42577
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
   
    // 사전순으로 정렬후, 앞의 문자와 뒤의 접두어가 일치하는지 확인
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size() - 1; i++) {
        if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size()))
            return false;
    }
    
    return true;
}
