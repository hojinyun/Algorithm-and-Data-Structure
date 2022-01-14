#include <iostream>
#include <stack>
#define LEFT 0
#define RIGHT 1

using namespace std;

int main(){
	int n;
	cin >> n;
	cin.ignore(); //getline() �� �� �ҷ����� ���� 
	for(int i = 0; i < n; i++){
		string str = "";
		getline(cin, str);
		stack<bool> stack;
		for(int j = 0; j < str.size(); j++){
			//���� ��ȣ �� �� ���ÿ� �ֱ� 
			if(str[j] == '(') stack.push(LEFT);
			//������ ��ȣ �� �� 
			else{
				/*������ ����� ���� Ȯ�ξ��ϸ� undefined behavior �߻�*/
				//������ �Ⱥ���� ���� ��ȣ�� �����ϸ� ���� ���� �ִ� ���ʰ�ȣ�� pop 
				if(!stack.empty() && stack.top()==LEFT) stack.pop();
				//������ ����ų� ���� ���� �ִ� ��ȣ�� ���� ��ȣ�� �ƴϸ� ��¥�� VPS�� �ƴϹǷ� break 
				else{
					stack.push(RIGHT); //����ִ� ������ ��쿡�� �Ʒ����� NO�� �ޱ� ���� RIGHT�� ���ÿ� push 
					break;
				}
			}
		}
		if(stack.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}	
