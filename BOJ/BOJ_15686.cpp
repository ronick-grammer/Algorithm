#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
vector<pair<int, int> > locations_houses; // 각 집들의 경로들
vector<pair<int, int> > locations_chickens; // 각 치킨집의 경로들

// 각 집들이 가지는 각 치킨집들의 모든 거리들 , ex) a집 -> 1치킨집 거리, a집 -> 2치킨집 거리, b집 -> 1치킨집 거리 ....
vector<vector<int> > distances_each; 
bool visited[13]; // 최대 13개의 치킨집의 방문여부(모든 경우를 구하기 위해)

int sum_min = 1e9;

void solve(int index, int count){
    
    if(index > locations_chickens.size()){ // 인덱스의 범위가 치킨집 갯수의 범위를 초과하면 종료
        return;
    }
    if(count == m){ // m 개의 치킨 집중에서 가장 짧은 경로를 택해야 한다
    
        int sum = 0;
        for(int i = 0; i < locations_houses.size(); i++){
            int distance_min = 1e9;
            for(int j = 0; j < locations_chickens.size(); j++){
                if(visited[j])
                    distance_min = min(distance_min, distances_each[i][j]); 
            }
            sum += distance_min;
        }
        sum_min = min(sum_min, sum);
        return;
    }
    
    // 모든 치킨집 중 m 개의 치킨집 중에서 각 집들 사이의 거리가 가장 짧은 걸 선택해야 하기 때문에
    // m 개만큼의 치킨집을 골라야 한다.
    visited[index] = true;
    solve(index + 1, count + 1);
    
    //위에서 해당 index의 치킨집은 방문해줬기 때문에 false 를 준다
    visited[index] = false;
    solve(index + 1, count);

}

int main(void){
    cin >> n >> m;

    for(int row = 1; row <= n; row++){
       for(int column = 1; column <= n; column++){
           int x;
           cin >> x;
           if(x == 1){
              locations_houses.push_back(make_pair(row, column)); // 집의 위치 정보 저장
           }
           else if(x == 2){
               locations_chickens.push_back(make_pair(row, column)); // 치킨집의 위치 정보 저장
           }
       }
    }
    

    for(int i = 0; i < locations_houses.size(); i++){
        vector<int> distances;

        for(int j = 0; j < locations_chickens.size(); j++){
            
            int distance = abs(locations_houses[i].first - locations_chickens[j].first) + 
                            abs(locations_houses[i].second - locations_chickens[j].second);

            distances.push_back(distance);  // 특정 집에 대한 모든 각 치킨집의 거리를 저장한다.
        }
        distances_each.push_back(distances);
    }

    solve(0, 0);
    cout<<sum_min<<endl;
}
