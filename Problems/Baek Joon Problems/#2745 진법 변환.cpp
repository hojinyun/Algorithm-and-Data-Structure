#include <iostream>

using namespace std;

int main(){
	string numbers;
	int n, answer=0;
	//�Է� 
	cin >> numbers >> n;
	//N������ �� 10�������� ��ȯ 
	for(int number: numbers){
		//���ĺ��� ���(11���� �̻��� ���) 
		if(number >= 'A' && number <= 'Z') answer = answer*n+(number-'A'+10);
		//������ ���(10���� ������ ���) 
		else if(number >= '0' && number <= '9') answer = answer*n+(number-'0');
	}
	//��� 
	cout << answer;
}
