//problem link: https://programmers.co.kr/learn/courses/30/lessons/1845
#include <vector>
using namespace std;

int kind[200001]; // 포켓몬 종류들

int solution(vector<int> nums)
{
    int answer = 0;
    int n = (int)nums.size() / 2;
    
    vector<int> v;
    for(int i = 0; i < nums.size(); i++){
        if(kind[nums[i]] == 0) { // 종류의 중복을 방지한다.
            v.push_back(nums[i]);
        }
        kind[nums[i]]++;
    }
    
    if(v.size() >= n) return n; // 종류가 충분해서 n보다 같거나 크면 n을 반환
    else return v.size(); // 종류가 충분하지 않으면 가진 종류의 최대 갯수 반환
}
