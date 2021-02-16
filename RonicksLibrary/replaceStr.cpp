// str 문자열에 포함된 from 문자열을 to 문자열로 교체한다
string replaceStr(string str, string from, string to){
    string newStr = str;
    int pos = 0;
    
    while((pos = newStr.find(from, pos)) != string::npos){
        newStr.replace(pos, from.size(), to);
        pos += to.size();
    }

    return newStr;
}
