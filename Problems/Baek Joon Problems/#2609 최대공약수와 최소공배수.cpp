#include <iostream>

using namespace std;

int main(){
	int first, second, multiple;
	//�Է�
	cin >> first;
	cin >> second;
	//�ּҰ����=�μ��� ��/�ִ������̹Ƿ� ���߿� �ּҰ���� ���� �� �ʿ��ϴ� 
	multiple = first*second;
	//��Ŭ���� ȣ���� ���� 
	while(first%second){
		int temp = first;
		first = second;
		second = temp%second;
	}
	//��� 
	cout << second <<'\n'<< multiple/second;
}
