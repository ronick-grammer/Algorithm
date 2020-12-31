#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
int team[100001];
vector<string> yesOrNO;

int findTeam(int x){ // 팀 찾기
    if(x == team[x]){
        return x;
    }
    else{
        return team[x] = findTeam(team[x]);
    }
}

void unionTeam(int a, int b){ // 팀 a 와 팀 b 를 합친다
    int team_a = findTeam(a);
    int team_b = findTeam(b);

    if(team_a < team_b){
        team[team_b] = team_a;
    }
    else{
        team[team_a] = team_b;
    }
}

int main(void){
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        team[i] = i;
    }

    for(int i = 0; i < m; i++){
        int option, a, b;
        cin >> option >> a >> b;

        if(option == 0){ // option 0 : 두 학생의 팀 합치기
            unionTeam(a, b);
        }
        else if(option == 1){ // option 1 : 두 학생의 팀 찾기
            if (findTeam(a) == findTeam(b)){
                yesOrNO.push_back("YES");
            }
            else{
                yesOrNO.push_back("NO");
            }
        }
    }

    for(int i = 0; i < yesOrNO.size(); i++){
        cout<<yesOrNO[i]<<endl;
    }
}
