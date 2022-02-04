#include <iostream>
#include <stack>

using namespace std;

int main(){
	int number, n;
	stack<char> answer;
	//�Է� 
	cin >> number >> n;
	//���� ��ȯ ���� 
	while(number > 0) {
		//�������� 10�̻��� ��� ���ÿ� ���ĺ� push(11���� �̻��� ���) 
		if(number%n >= 10) answer.push((char)('A'+number%n-10));
		//�������� 9������ ��� �������� ���ڰ� push(10���� ������ ���)
		else answer.push((char)(number%n+'0'));
		//���ڸ� �ݳ������� ������ �� 
		number /= n;
	}
	//��� 
	while(!answer.empty()){
		cout<<answer.top();
		answer.pop();
	}
}
