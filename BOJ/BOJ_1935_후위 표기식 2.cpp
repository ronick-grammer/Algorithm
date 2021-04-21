#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

//problem link: https://www.acmicpc.net/problem/1935

int n;
stack<double> sta;
string expression;
double result;

double getResult(double val_1, double val_2, char c){
    double resultGet;
    switch (c)
    {
        case '+':
            resultGet = val_1 + val_2;
            break;
        
        case '-':
            resultGet = val_1 - val_2;
            break;
        
        case '*':
            resultGet = val_1 * val_2;
            break;
        
        case '/':
            resultGet = val_1 / val_2;
            break;
        
        default:
            resultGet = 0;
    }

    return resultGet;
}

int main(void){
    cin >> n;
    cin >> expression;
    
    vector<double> v;
    for(int i = 0; i < n; i++){
        double x;
        cin >> x;
        
        v.push_back(x);
    }
    
    sta.push(v[expression[0] - 'A']);
    int pos = 1;
    while(!sta.empty() && pos < expression.size()){
        char x = expression[pos];
        if(x >= 'A' && x <= 'Z'){
            double val = v[x - 'A'];
            sta.push(val);
        }
        else{
            double val_1 = sta.top();
            sta.pop();
            double val_2 = sta.top();
            sta.pop();

            result = getResult(val_2, val_1, x);
            sta.push(result);
        }
        pos++;
    }

    printf("%.2f", result);
}
