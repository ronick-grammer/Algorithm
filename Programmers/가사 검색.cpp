#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//problem link: https://programmers.co.kr/learn/courses/30/lessons/60060?language=cpp

vector<string> strs[10001];
vector<string> strs_reverse[10001];

// 알파벳순으로 정렬된 strs 문자열들 중에서 from문자열과 to문자열 사이에 있는 문자열들의 갯수를 리턴한다
int countByRange(vector<string> ss, string from, string to){
    vector<string>::iterator right = upper_bound(ss.begin(), ss.end(), to);
    vector<string>::iterator left = lower_bound(ss.begin(), ss.end(), from);
    
    return right - left;
}

// str 문자열에 포함된 from 문자열을 to 문자열로 교체한다
string replace_str(string str, string from, string to){
    string newStr = str;
    int pos = 0;
    
    while((pos = newStr.find(from, pos)) != string::npos){
        newStr.replace(pos, from.size(), to);
        pos += to.size();
    }

    return newStr;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    for(int i = 0; i < words.size(); i++){
        string word = words[i];
        strs[word.size()].push_back(word); // 정순 저장 ('?' 와일드 카드가 앞에 붙어있을 경우-접두어)
        reverse(word.begin(), word.end()); // 문자열 뒤집기

        // 가사들을 역순으로도 저장하는 이유는 "????o" 같은 와일드 카드 '?' 문자가 앞에 붙어있는 
        // 키워드 문자열은 이진 탐색을 할 때에 알파벳 순으로 탐색을 할때 "????o" 를 "aaaao" 와 "zzzzo" 로 변환하여 
        // 이 두 문자열 사이에 있는 알파벳순으로 정렬된 가사들을 탐색할 수가 없기 때문이다.
        // '알파벳 순'으로 '이진 탐색'을 진행하는 것이 중요하다. 때문에 키워드 문자열 "????o" 키워드 문자열의 경우 나중에 "o????" 로 역순한 다음
        // "oaaaa" 와 'ozzzz"로 변환하여 이 두 문자열 사이에 있는 가사들을 탐색하기 위해 가사들 역시 역순으로도 저장해서 
        // 알파벳 순으로 정렬해야만 이진탐색 진행으로 "????o" 키워드와 매치된 가사들의 갯수를 알아낼 수가 있는 것이다.

        strs_reverse[word.size()].push_back(word); // 역순 저장('?'와일드 카드가 뒤에 붙어있을 경우-접미어)
    }

    for(int i = 1; i <= 10000; i++){ // 이진 탐색을 위해 문자열들을 알파벳 순으로 정렬
        sort(strs[i].begin(), strs[i].end());
        sort(strs_reverse[i].begin(), strs_reverse[i].end()); 
    }

    for(int i = 0; i < queries.size(); i++){
        string query = queries[i];
        int result;
        
        if(query[0] != '?'){ // 접두어일 경우
            result = countByRange(strs[query.size()], replace_str(query, "?", "a"), replace_str(query, "?", "z"));
        }
        else{ // 접미어일 경우
            reverse(query.begin(), query.end()); // 이진 탐색은 알파벳 순으로 가사들이 정렬 되어 있기에 키워드도 ㅇ
            result = countByRange(strs_reverse[query.size()], replace_str(query, "?", "a"), replace_str(query, "?", "z"));
        }
        answer.push_back(result);
    }
     
    return answer;
}
