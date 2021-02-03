#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

//problem link: https://www.acmicpc.net/problem/14888

int n;
int minNum = 1e9, maxNum = -1e9;
vector<int> numbers; // 오리지널 숫자들을 담을 변수
vector<char> operators; // 연산자들을 담을 변수
int result[11]; // 오리지널 숫자들을 가지고 연산한 결과값을 오른순으로 저장할 변수

char c[4] = {'+', '-', '*', '/'};


int get_result(int x, int y, char oper){
    switch (oper)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;

    default:
        return 0;
    }
}

int dfs(int x){
    if((x + 1) >= n){ // 연산할 숫자 만큼만 진행한다
        return 0;
    }

    for(int i = 0; i < 4; i++){
        if(operators[x] == c[i]){  // 두 값을 연산한 결과 값을 오른순으로 저장한다
            result[x + 1] = get_result(result[x], numbers[x + 1], c[i]); 
            dfs(x + 1); // 이제 다음 숫자와 연산을 한다
            break;
        }
    }

    return result[n-1]; // 연산된 결과값 반환
}

int main(void){
    cin>>n;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        numbers.push_back(x);
    }
    
    for(int i = 0; i < 4; i++){
        int x;
        cin >> x;
        for(int j = 0; j < x; j++){ // 연산자를 하나하나씩 저장해준다
            operators.push_back(c[i]);
        }
    }

    sort(operators.begin(), operators.end()); // next_permutation() 를 사용하기 위해 오름 차순 정렬 

    result[0] = numbers[0]; // 첫 숫자를 저장
    do{ // 연산자들을 가지고 만들 수 있는 가능한 모든 수의 경우의 수만큼 진행
        int sum = dfs(0);
        
        minNum = min(minNum, sum);
        maxNum = max(maxNum, sum);

    }while(next_permutation(operators.begin(), operators.end()));

    cout<<maxNum<<endl;
    cout<<minNum<<endl;
}
