//problem link: https://programmers.co.kr/learn/courses/30/lessons/17677
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int solution(string str1, string str2) {

    vector<string> splitedStr1, splitedStr2;
    
    // 모두 소문자로 변경
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    // 영문자가 아닌 문자들은 제외
    for(int i = 0; i < str1.size() - 1; i++) {
        if(str1[i] >= 'a' && str1[i] <= 'z' && str1[i+1] >= 'a' && str1[i+1] <= 'z')
            splitedStr1.push_back(str1.substr(i, 2));
    }
    for(int i = 0; i < str2.size() - 1; i++) {
        if(str2[i] >= 'a' && str2[i] <= 'z' && str2[i+1] >= 'a' && str2[i+1] <= 'z')
            splitedStr2.push_back(str2.substr(i, 2));
    }

    // sum : 합집합, sub : 교집합
    int sum = splitedStr1.size() + splitedStr2.size(); // 우선 모든 요소를 모두 더한 후에, 나중에 교집합을 빼주면 합집합이 된다.
    int sub = 0;

    // 교집합 구하기
    for(int i = 0; i < splitedStr1.size(); i++){
        // find 함수는 이번에 처음 알게 되었는데, 특정 집합에서 특정 값이 있는 요소의 위치를 반환한다. 없으면 끝 iterator.end() 를 반환한다. 
        vector<string>::iterator iter = find(splitedStr2.begin(), splitedStr2.end(), splitedStr1[i]);
        if(iter != splitedStr2.end()){ // 서로 겹치는 것이 교집합
            sub++;
            splitedStr2.erase(iter); // 겹쳤던 건 삭제해서 중복을 피하도록 하자
        }
    }
    
    sum -= sub; // 두 요소의 합에서 교집합을 빼주면 합집합
    if(sum == 0) // 0으로 나눌 수는 없으므로 
        return 65536;

    double answer = (double)sub / (double)sum; // double 안해주면 에러가 난다.
    answer *= 65536;
    return answer;
}
