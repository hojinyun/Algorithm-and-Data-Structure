#include <iostream>

using namespace std;

int main(){
	int E, S, M, year=1;
	//�Է�
	cin >> E >> S >> M;
	//year�� �������� E, S, M���� ������ ��� while�� ����
	while(!((year-E)%15==0 && (year-S)%28==0 && (year-M)%19==0)) year++;
	//���
	cout<<year;
}
