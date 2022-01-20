#include <iostream>
#include <stack>

using namespace std;

int amount[1000000] = {}; // �߰� �� �迭 ����

int main(){
	int n;
	stack<int> s, NGF, answer;

	//�Է�
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		//�� ���ڸ� �ε����� ��Ÿ���� �� ������ ������ �迭�� ����
		amount[temp]++; // �߰� �� �迭 ����
		s.push(temp);
	}
	
	while(!s.empty()){
		//���� ������ ���ڰ� �ƴ� �� 
		if(!NGF.empty()){
			//������ ���ڰ� Ŭ �� 
			if(amount[s.top()] < amount[NGF.top()]){ //���� �� if��
				answer.push(NGF.top());
				NGF.push(s.top());
				s.pop(); 
			}
			//������ ���ڰ� ���� �� 
			else{
				NGF.pop();
			}
		}
		//���� ������ ���ڿ��� NGF�� ������� ��
		else{
			answer.push(-1);
			NGF.push(s.top());
			s.pop();
		}
	}
	//���� ���
	for(int i = 0; i < n; i++){
		if(!answer.empty()){
			cout << answer.top() << " ";
			answer.pop();
		}
	}
}
