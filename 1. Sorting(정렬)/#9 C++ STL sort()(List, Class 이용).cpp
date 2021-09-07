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
	//���� ������ '������ ���� ����' 
	bool operator <(Student &student){
		return this -> score < student.score;
	}
};

int main(void){
	Student students[] = {
		Student("��ȣ��", 90),
		Student("�̽���", 92), 
		Student("�ּ���", 93), 
		Student("������", 97),
		Student("����ȣ", 91),
	};
	sort(students, students + 5);
	for(int i = 0; i < 5; i++){
		cout << students[i].name << ' ';
	}
}
