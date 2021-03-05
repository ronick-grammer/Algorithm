// str 문자열에서 split 문자열을 기준으로 문자열들을 분할한다
vector<string> splitStringByString(string &str, string &split){ 
    vector<string> splitedStrings;  
    
    string newStr = str;
    int pos = 0; // split 문자열의 위치
    int current_index = 0; // 분할해서 담을 문자열의 위치

    // split 문자열이 있는 문자열의 위치를 왼쪽에서부터 찾는다.
    while((pos = newStr.find(split, pos)) != string::npos){ 
        
        splitedStrings.push_back(newStr.substr(current_index, pos - current_index));
        
        pos += split.size(); // 찾았으면 split 문자열을 찾은 위치의 다음 위치부터 찾는다.
        
        current_index = pos; // 분할해서 담을 문자열의 위치
    }
    
    splitedStrings.push_back(newStr.substr(current_index)); // 마지막 문자열을 담는다

    return splitedStrings;
}
