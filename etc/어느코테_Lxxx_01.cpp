#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;

#define EMPTY 0

//problem link: 비공개, 비밀이지롱

int solution(int n, vector<string> recipes, vector<string> orders) {
    int answer;
    vector<int> stove(n, EMPTY);
    vector<pair<string, int> > newRecipes;
    vector<pair<string, pair<int, int> > > newOrders; // 메뉴, 오더시간, 처리시간
    
    // recipes 메뉴와 시간 분리
    for(int i = 0; i < recipes.size(); i++){
        stringstream ss(recipes[i]);
        vector<string> token;
        string buf;
        while(ss>>buf){
            token.push_back(buf);
        }
        newRecipes.push_back(make_pair(token[0], stoi(token[1])));
    }
    
    // orders 메뉴와 시간 분리
    for(int i = 0; i < orders.size(); i++){
        stringstream ss(orders[i]);
        vector<string> token;
        string buf;
        int cookingTime = 0;
        while(ss>>buf){
            token.push_back(buf);
        }

        for(int j = 0; j < newRecipes.size(); j++){
            if(newRecipes[j].first == token[0]){ // 메뉴 이름으로 처리시간 찾기
                cookingTime = newRecipes[j].second;
                break;
            }
        }
        // 메뉴, 주문시간, 처리시간을 넣어준다
        newOrders.push_back(make_pair(token[0], make_pair(stoi(token[1]), cookingTime)));
    }

    for(int i = 0; i < newOrders.size(); i++){
        int current_orderTime = newOrders[i].second.first; // 현재 메뉴 주문 시간
        int current_cookingTime = newOrders[i].second.second; // 현재 메뉴 처리 시간
        
        int minTime = 1e9;
        int minIndex = 11;
        for(int stoveNumber = 0; stoveNumber < stove.size(); stoveNumber++){
           
            if(stove[stoveNumber] <= current_orderTime){ // 현재 스토브가 사용시간이 다 끝났다면
                minTime = current_orderTime + current_cookingTime;
                minIndex = stoveNumber;
               
                break;
            }
            
            // 그게 아니라면 스토브들 중 사용 했을 때 가장 처리시간이 빨리 끝나는 걸로 선택
            if(stove[stoveNumber] + current_cookingTime < minTime){
                minTime = stove[stoveNumber] + current_cookingTime;
                minIndex = stoveNumber;
            }
        }
        stove[minIndex] = minTime; // 메뉴가 끝나는 시간 저장
        answer = minTime;
    }
    
    return answer;
}
