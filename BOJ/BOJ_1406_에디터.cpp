#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

string s;
int m;
char commend[500001][2];

int main(void){
    cin >> s;
    cin >> m;
    for(int i = 0; i < m; i++){
        scanf(" %c", &commend[i][0]);
        if(commend[i][0] == 'P'){
            scanf(" %c", &commend[i][1]);
        }
    }
    list<char> l(s.begin(), s.end());

    // 기존 string을 사용하지 않는 이유는
    // string의 erase 나 insert는 한번 요소의 변동이 일어나면 다른 요소들의 위치를 또 이동시켜야 하기 때문에
    // 시간 초과가 발생하기 때문이다.
    // 반면 list는 요소를 삭제하면 다른 요소들의 위치를 전부 이동 시킬 필요가 없다.
    list<char>::iterator cursor = l.end(); // 커서의 위치를 가장 뒤에 놓는다.

    for(int i = 0; i < m; i++){
        if(commend[i][0] == 'L'){
            if(cursor != l.begin())
                cursor--;
        }
        else if(commend[i][0] == 'D'){
            if(cursor != l.end())
                cursor++;
        }
        else if(commend[i][0] == 'B'){
            if(cursor != l.begin()){
                cursor = l.erase(--cursor);
            }
        }
        else if(commend[i][0] == 'P'){
            l.insert(cursor, commend[i][1]);
        }
    }
    
    for(list<char>::iterator iter = l.begin(); iter != l.end(); iter++){
        cout<<*iter;
    }
}
