//problem link: https://programmers.co.kr/learn/courses/30/lessons/42890
#include <string>
#include <vector>
#include <set>
using namespace std;

// 최소성 체크
bool validate(vector<int> tuples, int columnComb) {
    
    // 후보키 속성중에서 하나라도 포함하고 있다는 것은 그 후보키 속성이 없으면 최소성을 만족하지 못하는 것을 의미한다.
    // 후보키가 하나라도 포함되어 있어서 그 후보키를 빼더라도 남은 속성의 집합으로도 유일성을 가질 수 있고 
    // 따라서 최소성을 만족하는 후보키가 될수 있지 않을까 생각할 수도 있지만 그럴수 없다. 
    // 왜냐하면 로직에 따라 남은 속성들은 이미 후보키로 등록되어 있기에 중복이 되기 때문이다. 
    for(int i = 0; i < tuples.size(); i++) {
        if((tuples[i] & columnComb) == tuples[i])
            return false;
    }
    
    return true;
}

int solution(vector<vector<string>> relation) {
    
    int n = relation[0].size();
    vector<int> validTuples; // 후보키
    
    //비트 마스크로 모든 집합 만들기
    for(int i = 1; i < (1 << n); i++) {
        set<string> tuples; 
        // 각 행별로 튜플을 만들어서 집합에 넣어 중복 처리하기
        for(int row = 0; row < relation.size(); row++) {
            string tuple = "";
            for(int column = 0; column < n; column++) {
                // 속성들의 값으로 튜플을 만들어줌
                if(i & (1 << column))
                    tuple += relation[row][column];
            }
            tuples.insert(tuple); // 중복처리
        }
        
        // 튜플의 사이즈가 relation 행 사이즈와 같다는 것은 중복되는 튜플이 없으며 따라서 
        // 후보키가 될 수 있다는 것을 의미한다. 하지만 후보키를 이루는 속성 중 이미 후보키로 등록된 조합
        if(tuples.size() == relation.size() && validate(validTuples, i))
            validTuples.push_back(i);
    }
    
    return validTuples.size();
}
