#include <iostream>

using namespace std;

int main(){
	int n, first, second, multiple;
	//�Է� 
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> first;
		cin >> second;
		multiple = first*second;
		//��Ŭ���� ȣ�������� �ִ������� ���� 
		while(second%first){
			int temp = second;
			second = first;
			first = temp%first;
		}
		//�ּҰ����=�μ��� ��/�ִ�����
		cout << multiple/first <<'\n';
	}
}
