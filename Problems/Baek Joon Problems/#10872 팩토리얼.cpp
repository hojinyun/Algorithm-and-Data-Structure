#include <iostream>

using namespace std;

int main(){
	int n, answer = 1;
	//�Է�
	cin >> n;
	//n�����ϳ��� ���鼭 ���丮�� ��� 
	while(n){ 
		answer *= n;
		n--;
	}
	//��� 
	cout<<answer;
}
