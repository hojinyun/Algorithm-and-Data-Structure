#include <iostream>

using namespace std;

int main(){
	long long n, m, num_two = 0, num_five = 0, two_multiple=2, five_multiple = 5;
	//�Է� 
	cin >> n >> m;
	//---------5�� ����--------------
	//n�� �ִ� 5�� ���� �����ֱ�
	while(n/five_multiple){
		num_five+=n/five_multiple;
		five_multiple*=5;
	}
	//5�� ��� �ʱ�ȭ
	five_multiple = 5;
	//m�� �ִ� 5�� ���� ���ֱ�
	while(m/five_multiple){
		num_five-=m/five_multiple;
		five_multiple*=5;
	}
	//5�� ��� �ʱ�ȭ
	five_multiple = 5;
	//n-m�� �ִ� 5�� ���� ���ֱ�
	while((n-m)/five_multiple){
		num_five-=(n-m)/five_multiple;
		five_multiple*=5;
	}
	//---------2�� ����--------------
	//n�� �ִ� 5�� ���� �����ֱ�
	while(n/two_multiple){
		num_two+=n/two_multiple;
		two_multiple*=2;
	}
	//2�� ��� �ʱ�ȭ
	two_multiple = 2;
	//m�� �ִ� 2�� ���� ���ֱ�
	while(m/two_multiple){
		num_two-=m/two_multiple;
		two_multiple*=2;
	}
	//2�� ��� �ʱ�ȭ
	two_multiple = 2;
	//n-m�� �ִ� 2�� ���� ���ֱ�
	while((n-m)/two_multiple){
		num_two-=(n-m)/two_multiple;
		two_multiple*=2;
	}
	//�ΰ��� ���� �ּڰ� ���
	cout << min(num_two, num_five); 
}
