#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n;
	stack<char> left, right;
	string s = "";
	
	getline(cin, s);
	cin >> n;

	//��� ���ڿ��� ���� ���ÿ� �ֱ�
	for(int i = 0; i < s.size(); i++) left.push(s[i]);
	
	for(int i = 0; i < n; i++){
		char temp;
		cin >> temp;
		
		if(temp == 'L'){
			if(!left.empty()){
				//�������� �Ѿ�� ���ʿ� �ִ� ���� ���������� �������� ���� ��
				right.push(left.top());
				left.pop();
			}
		}
		else if(temp == 'D'){
			//���� ���� �ݴ�
			if(!right.empty()){
				left.push(right.top());
				right.pop();
			}
		}

		else if(temp == 'B'){
			if(!left.empty()) left.pop();
		}

		else if(temp == 'P'){
			char letter;
			cin >> letter;
			left.push(letter);
		}
	}

	//���� ����� �پ��� ���� �����ϱ� ���� ���� ����
	int left_size = left.size();
	//��� �� ���ϰ� ��� ���ڵ� ������ �������� �ű��
	for(int i = 0; i < left_size; i++){
		right.push(left.top());
		left.pop();
	}
	
	//���� ���������� ���� ����� �پ��� ���� �����ϱ� ���� ���� ����
	int right_size = right.size();
	for(int i = 0; i < right_size; i++){
		cout << right.top();
		right.pop();
	}
}
