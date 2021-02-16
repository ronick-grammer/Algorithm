// next_permutation 에 의한 순열에 따른 2차원 배열의 방문위치를 반환한다
vector<pair<int, int> > Get_Next_TwoDimensionalArrayLocations(vector<bool>& visited, int columnSize){ 
    vector<pair<int, int> > locations; // row, column

    for(int i = 0 ; i < visited.size(); i++){
        if(visited[i] == true){ // 방문할 곳이면 그 위치를 저장한다
            int row = i / columnSize; // 행 계산
            int column = i % columnSize; // 열 계산
            
            // 방문할 위치 기억
            locations.push_back(make_pair(row, column));
        }
    }
    return locations;
}
