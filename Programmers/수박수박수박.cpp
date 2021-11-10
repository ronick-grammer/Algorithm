#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer;
    
    for(int i = 1; i <= n; i++) {
        answer += (i % 2 == 1) ? "수" : "박";
    }
    
    return answer;
}
