#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s; // 숫자를 담을 문자열
vector<int> v; // 문자열을 숫자로 변환할 정수배열
int sum; // 최대 결과를 담을 변수

int main(void){
    cin>>s;

    for(int i = 0; i < s.size(); i++){
        int x = s[i] - '0'; // 문자열의 각 문자를 숫자로 변환
        v.push_back(x);
    }

    if(v[0] <= 1 || v[1] <= 1){ // 가장 맨 앞의 두 숫자중 하나라도 1 이하이면 더한다
        sum += v[0] + v[1];
    }
    else{ // 2 이상이면 곱한다
        sum += v[0] * v[1];
    }
    
    for(int i = 2; i < v.size(); i++){ // 위에서 앞의 두 숫자를 처리하였으므로 세번째 숫자부터 진행한다
        if(v[i] <= 1){ // 1 이하이면 더하는 것이 더 크다
            sum += v[i];
        }
        else{ // 2 이상이면 곱하는 것이 더 크다
            sum *= v[i];
        }        
    }

    cout<<sum<<endl;
}
