#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

//problem link: https://programmers.co.kr/learn/courses/30/lessons/72411#qna

vector<string> solution(vector<string> orders, vector<int> course) {

    for(int i = 0; i < orders.size(); i++){
        sort(orders[i].begin(), orders[i].end()); // 모든 메뉴들 알파벳 순으로 정렬
    }

    vector<string> v[11]; // 코스 메뉴는 최대 10개.
    for(int i = 0; i < orders.size(); i++){  // 1. 각 손님이 시킨 단품 메뉴들에서
        for(int j = 0; j < course.size(); j++){ // 2. 각 코스 요리에 들어갈 단품 메뉴 갯수만큼
            int index = course[j];

            if(orders[i].size() > index){ // 각 손님이 시킨 단품 메뉴의 갯수가 코스 요리를 구성하는 단품메뉴의 갯수보다 크면 진행
                vector<bool> visited(orders[i].size(), false); // 각 단품메뉴 갯수의 모든 조합을 만들어 낸다
                fill(visited.end() - index, visited.end(), true);
                
                do{  // 3. 가능한 모든 조합을 만들어 

                    string str = ""; 
                    for(int k = 0; k < visited.size(); k++){
                        if(visited[k]){
                            str += orders[i][k];
                        }
                    }
                    v[index].push_back(str); // 4. 각 코스요리를 구성하는 단품메뉴 갯수 별로 각각 저장

                } while (next_permutation(visited.begin(), visited.end()));
                
            }
            else if(orders[i].size() == index){  // 같다면 그냥 넣어준다
                v[index].push_back(orders[i]);
            }
        }
    }

    vector<string> answer;
    for(int i = 0; i < course.size(); i++){
        int index = course[i];
        
        sort(v[index].begin(), v[index].end()); // 알파벳 순으로 정렬 이진 탐색을 위해

        int max = 2; // 최소 두 개의 단품 메뉴들이어야만 코스 요리로 등록 될 수 있으므로
        vector<string> course;
        for(int j = 0; j < v[index].size();){
            // 코스요리를 구성하는 단품메뉴들의 갯수별로 알파벳 순으로 정렬된 단품 메뉴들을 이진탐색을 진행하여
            // 가장 많이 주문된 메뉴 구성을 찾는다
            vector<string>::iterator lower = lower_bound(v[index].begin(), v[index].end(), v[index][j]);
            vector<string>::iterator upper = upper_bound(v[index].begin(), v[index].end(), v[index][j]);
            
            int courseIndex = lower - v[index].begin(); // 코스요리를 구성할 조합된 단품 메뉴들의 문자열 위치
            
            if(upper - lower == max){ // 가장 많이 함께 주문된 메뉴 구성이 여러 개라면 
                course.push_back(v[index][j]); // 그것 또한 저장해준다
            }
            else if(upper - lower > max){ // 메뉴 구성이 가장 많이 함께 주문 된 것이라면 
                max = upper - lower; // 가장 많이 주문된 해당 메뉴 구성의 갯수를 새로 저장
                course.clear(); // 기존에 저장해 놓은 것이 있을시에 전부 지워주고
                course.push_back(v[index][j]); // 새로 가장 많이 함께 주문 된 메뉴 구성을 저장한다
            }
            j = upper - v[index].begin(); // 다음 메뉴 구성으로 이동
        }
        for(int k = 0; k < course.size(); k++){ // 가장 많이 함께 주문된 메뉴 구성들 혹은 메뉴 구성을
            answer.push_back(course[k]); // 저장
        }
    }

    sort(answer.begin(), answer.end()); // 마지막에 정렬해서 반환
    return answer;
}
