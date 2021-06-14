//problem link: https://www.acmicpc.net/problem/14889
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int map[20][20];

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf(" %d", &map[i][j]);
        }  
    }

    vector<bool> visited(n, false);
    fill(visited.end() - (n / 2), visited.end(), true);

    int result = 1e9;
    do
    {
        vector<int> teamStart, teamLink;
        for(int i = 0; i < visited.size(); i++){
            if(visited[i]) teamStart.push_back(i);
            else teamLink.push_back(i);
        }

        int sumStart = 0, sumLink = 0;
        for(int i = 0; i < n / 2; i++){
            for(int j = 0; j < n / 2; j++){
                sumStart += map[teamStart[i]][teamStart[j]];
                sumLink += map[teamLink[i]][teamLink[j]];
            }
        }

        result = min(result, abs(sumStart - sumLink));
    } while (next_permutation(visited.begin(), visited.end()));
    
    cout<<result<<'\n';
}
