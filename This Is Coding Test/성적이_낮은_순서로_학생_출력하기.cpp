#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 성적이 낮은 순서로 학생 출력하기

int n;

class Student{
    string name;
    int score;

    public: 

    Student(string name, int score){
        this->name = name;
        this->score = score;
    }

    string getName(){
        return this->name;
    }

    bool operator<(const Student &other) const{
        return this->score < other.score;
    }
};

int main(void){
    vector<Student> students;

    cin>>n;
    for(int i = 0; i < n; i++){
        string name;
        int score;
        cin >> name >> score;
        students.push_back(Student(name, score));
    }

    sort(students.begin(), students.end());

    for(int i = 0; i < n; i++){
        cout<<students[i].getName()<<endl;
    }
}
