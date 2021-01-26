#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// problem link: https://programmers.co.kr/learn/courses/30/lessons/72410

string solution(string new_id) {
    string answer = "";
    //1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    for(int i = 0; i < new_id.length(); i++){
        //2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
        if(!(new_id[i] >= 'a' && new_id[i] <= 'z')){
            if(!(new_id[i] >= '0' && new_id[i] <= '9')){
                if((new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.')){
                    new_id.erase(i, 1);
                    i--;
                }
            }
        }
        //3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
        if(i != 0 && new_id[i-1] == '.' && new_id[i] == '.'){
            new_id.erase(i-1, 1);       
            i--;
        }
    }

    //4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    if(new_id.front() == '.'){
        new_id.erase(0, 1);
    }
    if(new_id.back() == '.'){
        new_id.erase(new_id.length()-1, 1);
    }

    //5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if(new_id.empty()){
        new_id = "a";
    }


    //6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    // 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    if(new_id.length() >= 16){
        new_id.erase(15, new_id.length() - 15);
        if(new_id.back() == '.'){
            new_id.erase(new_id.length() - 1, 1);
        }
    }

    //7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    if(new_id.length() <= 2){
        new_id.append(3 - new_id.length(), new_id.back());
    }

    answer = new_id;

    return answer;
}
