#include <iostream>
#include <string>
using namespace std;

string s; // 숫자를 담을 문자열
int sum[20]; // 문자열을 숫자로 변환할 정수배열
int result; // 최대 결과를 담을 변수

int main(void){
    cin>>s;

    for(int i = 0; i < s.size(); i++){
        sum[i] = s[i] - '0'; // 문자열의 각 문자를 숫자로 변환
    }

    result = sum[0]; 
    for(int i = 1; i < s.size(); i++){ // 숫자들의 갯수만큼 반복
        
        if(result <= 1){ // 1보다 작거나 같으면 더한다. 1 이하인 수를 곱한 것보다 더하는 것이 합이 더 커지기 때문이다
            result = result + sum[i];
        }
        else{    // 1보다 크면 곱한다. 2이상인 수를 더하는 것보다 곱하는 것이 합이 더 커지기 때문이다
            result = result * sum[i];
        }
    }

    cout<<result<<endl;
}
