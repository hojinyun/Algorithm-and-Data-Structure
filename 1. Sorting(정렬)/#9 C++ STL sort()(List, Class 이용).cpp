#include <iostream>
#include <algorithm>

using namespace std;

/*bool compare(int a, int b){
	return a > b;
}*/

class Student {
public:
	string name;
	int score;
	Student(string name, int score){
		this -> name = name;
		this -> score = score;
	}
	//정렬 기준은 '점수가 작은 순서' 
	bool operator <(Student &student){
		return this -> score < student.score;
	}
};

int main(void){
	Student students[] = {
		Student("윤호진", 90),
		Student("이승준", 92), 
		Student("최세민", 93), 
		Student("권찬혁", 97),
		Student("이재호", 91),
	};
	sort(students, students + 5);
	for(int i = 0; i < 5; i++){
		cout << students[i].name << ' ';
	}
}
