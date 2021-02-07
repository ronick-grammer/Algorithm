#include <iostream>
#include <vector>
using namespace std;

// 열쇠 회전(2차원 배열 시계 방향으로 90 도 회전)
vector<vector<int> > rotateMatrix(vector<vector<int> > original){ 

    int size_row = original.size(); // 열쇠의 행 길이
    int size_column = original[0].size(); // 열쇠의 열 길이
    vector<vector<int> > rotated(size_row);
    
    for(int i = 0; i < size_row; i++){ // 회전 가즈아!!!
        for(int j = 0; j < size_column; j++){
            rotated[i].push_back(original[size_row - j - 1][i]);
        }
    }
    return rotated;
}
