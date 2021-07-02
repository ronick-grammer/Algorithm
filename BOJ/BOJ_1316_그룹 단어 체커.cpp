#include <iostream>
#include <string>
using namespace std;

int n;
string s[100];
int result;

int main(void){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s[i];
    }
    
    result = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < s[i].size()-1; j++){
            char c = s[i][j];
            int foundIndex = s[i].find(c, j+1); // 자신과 같은 단어의 위치를 찾는다.

            // 연속된 문자가 아니면 하나씩 감소
            if(j + 1 != foundIndex && foundIndex != -1) { 
                result--;
                break;
            }
        }
    }

    cout<<result<<'\n';
}
