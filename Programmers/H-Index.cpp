//problem link: https://programmers.co.kr/learn/courses/30/lessons/42747
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();   
    sort(citations.begin(), citations.end());
    
    //정렬후 이진탐색으로 값 찾기
    for(int i = 0; i <= citations.back(); i++) {
        vector<int>::iterator left = lower_bound(citations.begin(), citations.end(), i);
        
        int index = left - citations.begin();
        // h번 이상 이상이고, 나머지가 h번 이하 인용되었다면
        if(size - index >= i &&  index <= i)
            answer = i;
    }
    
    return answer;
}
