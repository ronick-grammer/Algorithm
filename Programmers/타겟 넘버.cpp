#include <string>
#include <vector>

using namespace std;

int n;
int result;

void dfs(vector<int> numbers, int target, int x, int value){
    if(x == n){ // 모든 숫자에 대한 연산이 끝났으면 
        if(value == target) // 결과가 target이랑 같은지 확인한다.
            result++;
        return;        
    }
    
    dfs(numbers, target, x + 1, value + numbers[x]); // 더했을 경우
    dfs(numbers, target, x + 1, value - numbers[x]); // 뺏을 경우
}

int solution(vector<int> numbers, int target) {
    n = numbers.size();
    
    dfs(numbers, target, 0, 0);
    
    return result;
}
