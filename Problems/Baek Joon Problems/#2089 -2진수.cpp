#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n;
	stack<int> binary;
	//�Է�
	cin >> n;
	//0�� ��� ���� ó��
	if(n==0){
		cout<<0;
		return 0;
	}
	//���������� ��ȯ ����
	while(n){ 
		//�������� 1�� ���(Ȧ���� ���)
		if(n%-2) binary.push(1);
		//�������� 0�� ���(¦���� ���)
		else binary.push(0);
		//n�� ������� �״�� ������ �ָ� �Ǵ� ���
		if(n>0) n/=-2;
		//n�� �������� ¦���� Ȧ���� ������ ���
		else if(n<0){
			//�����ε� ¦���� ��� ������ �������Ƿ� �״�� ������
			if(n%2==0) n=n/-2;
			//�����ε� Ȧ���� ��쿡�� -2�� ���� �� �ݳ����� �Ǳ� ������ 1�� ���Ͽ� �ݿø�
			else n=n/-2+1;
		} 
	}
	//���
	while(!binary.empty()){
		cout<<binary.top();
		binary.pop();
	}
}
