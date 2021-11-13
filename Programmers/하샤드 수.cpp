#include <string>
#include <vector>
using namespace std;

bool solution(int x) {
    
    string number_str = to_string(x);
    int sum = 0;
    
    // 각 자리의 요소들 
    for(int i = 0; i < number_str.size(); i++) {
        sum += number_str[i] - '0';
    }
    
    return (x % sum == 0);
}
