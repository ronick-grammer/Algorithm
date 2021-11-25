//problem link: https://programmers.co.kr/learn/courses/30/lessons/42746
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 두 숫자의 순서가 바뀌었을때 더 큰게 앞으로 오도록 정렬
bool compare(int a, int b) {
    
    string greater_a = to_string(a) + to_string(b);
    string greater_b = to_string(b) + to_string(a);
    
    return stoi(greater_a) > stoi(greater_b); 
       
}

string solution(vector<int> numbers) {
    
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);
    for(int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    
    // numbers 모든 요소가 0이면 "0000...0" 식이 아니라 "0" 이 리턴되야함
    if(answer[0] == '0') return "0";
    
    return answer;
}
