#include <iostream>
using namespace std;

int main(void){
    int n, k;
    int cnt = 0;   

    cin >> n >> k;

    while(n != 1){
        
        if(n % k == 0){
            n = n / k;
        }
        else{
            n--;
        }
        cnt++;
    }

    cout<<cnt<<endl;
}
