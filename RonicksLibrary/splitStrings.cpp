#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>


vector<string> splitString(string str, char c){
    vector<string> splitedStrings; 
    istringstream iss(str);

    string token;
    while(getline(iss, token, c)){ // c 문자를 기준으로 문자열이 나누어진다
        splitedStrings.push_back(token);
    }

    return splitedStrings;
}
