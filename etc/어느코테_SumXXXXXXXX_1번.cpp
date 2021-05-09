#include <string>
#include <vector>

using namespace std;

class StockData{
public:
    int price;
    int hour;
    StockData(int price, int hour){
        this->price = price;
        this->hour = hour;
    }

    bool operator <(const StockData &other) const{
        return this->hour < other.hour;
    }
};
// code 와 day 가 일치하는 data의 가격을 시간이 빠른 순으로 정렬하여 반환하기
vector<int> solution(string code, string day, vector<string> data) {
    vector<int> answer;
    vector<StockData> stockData;
    for(int i = 0; i < data.size(); i++){
        int pricePosFrom = data[i].find("=", 0) + 1;
        int pricePosTo = data[i].find(" ", 0);
        int price = stoi(data[i].substr(pricePosFrom, pricePosTo - pricePosFrom));

        int codePosFrom = data[i].find("code", pricePosTo) + 5;
        string Ncode = data[i].substr(codePosFrom, 6);

        int datePosFrom = data[i].find("time", codePosFrom + 6) + 5;
        string date = data[i].substr(datePosFrom, 8);
        int hour = stoi(data[i].substr(datePosFrom + 8));

        if(code == Ncode && day == date)
            stockData.push_back(StockData(price, hour));
    }

    sort(stockData.begin(), stockData.end());
    for(int i = 0; i < stockData.size(); i++){
        answer.push_back(stockData[i].price);
    }
    
    return answer;
}
