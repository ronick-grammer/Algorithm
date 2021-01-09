#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// problem link: https://www.acmicpc.net/problem/1439

int count_zero, count_one; // 연속된 0의 숫자 갯수와 연속된 1의 갯수
char prevNumber, nextNumber; // 연속된 숫자인지 아닌지 비교하기 위한 변수들
string s;

int main(void){
    cin>>s;
    
    prevNumber = s[0];
    if(prevNumber == '0'){ // 첫 문자가 0이라면 count_zero 증가
        count_zero++; 
    }
    else if(prevNumber == '1'){ // 첫 문자가 1이라면 count_one 증가
        count_one++;
    }


    for(int i = 1; i < s.size(); i++){ // 첫 문자은 처리 되었으므로 인덱스 1부터 시작
        nextNumber = s[i]; 
        if(prevNumber != nextNumber){ // 전 숫자와 다음(현재)숫자가 다른데 
            if(nextNumber == '0'){ // 문자가 0이라면 count_zero 증가
                count_zero++;
            }
            else if(nextNumber == '1'){ // 문자가 문자가 1이라면 count_one 증가
                count_one++;
            }
        }
        prevNumber = nextNumber; 
    }

    cout<<min(count_zero, count_one); // 연속된 0의 숫자들의 갯수와 연속된 1의 숫자들의 갯수중 작은 것을 출력 
}
