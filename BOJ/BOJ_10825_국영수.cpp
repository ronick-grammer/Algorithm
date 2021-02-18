#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//probelm link: https://www.acmicpc.net/problem/10825

// 과목의 성적순 혹은 이름순으로 정렬하기
class Student{
    public:
    string name;
    int score_korean;
    int score_english;
    int score_math;

    Student(string name, int score_korean, int score_english, int score_math){
        this->name = name;
        this->score_korean = score_korean;
        this->score_english = score_english;
        this->score_math = score_math;
    }

    bool operator <(Student &other) {

        if(this->score_korean == other.score_korean && this->score_english == other.score_english 
            && this->score_math == other.score_math){
            return this->name < other.name;
        }
        if(this->score_korean == other.score_korean && this->score_english == other.score_english){
            return this->score_math > other.score_math;
        }
        if(this->score_korean == other.score_korean){
            return this->score_english < other.score_english;
        }
        
        return this->score_korean > other.score_korean;
    }
};

int n;
vector<Student> students;

int main(void){
    cin>>n;

    for(int i = 0; i < n; i++){
        string name;
        int score_korean;
        int score_english;
        int score_math;
        cin >> name >> score_korean >> score_english >> score_math;
        students.push_back(Student(name, score_korean, score_english, score_math));
    }

    sort(students.begin(), students.end());

    for(int i = 0; i < n; i++){
        // '\n' 으로 줄바꿈을 해야 시간 초과가 안난다. endl 은 출력버퍼에서 시간을 많이 잡아먹는다
        cout<<students[i].name<<'\n'; 
    }
}
