#include<iostream>
#include<stack>

using namespace std;

int priority(char operators){
	switch(operators){
		case '(': return 3;
		case '*': return 2;
		case '/': return 2;
		case '+': return 1;
		case '-': return 1;
	}
}

int main(){
	stack<char> operators;
	string equation;
	//�Է�
	getline(cin, equation);
	for(int i = 0; i < equation.size(); i++){
		//�������� ���
		if(equation[i]=='+'||equation[i]=='-'||equation[i]=='*'
				||equation[i]=='/'||equation[i]=='('||equation[i]==')'){
			//�����ڰ� �ִ� ��� 
			if(!operators.empty()){
				//��ȣ�� �����Ƿ� �� ���̿� �ִ� ������ ��� ��� 
				if(equation[i] == ')'){
					while(operators.top() != '('){
						cout<<operators.top();
						operators.pop();
					}
					operators.pop();
				}
				//���� ������ �����ڰ� �켱������ ���� ���
			  //operators.top()�� '('�϶� priority�� �۾Ƶ� ���� �����ڰ� ���� �� �ֵ��� ��
				else if(priority(operators.top()) < priority(equation[i])||operators.top()=='('){
					operators.push(equation[i]);
				}
				//���� ������ �����ڰ� �켱������ ���ų� ���� ���
				else{
					cout<<operators.top();
					operators.pop();
					/*�ѹ� pop�� �� ���� ���� operator�� pop�� operator�� ���� ������ ���� �����Ƿ�
						(���� ũ��� ���� �̹� pop �ƾ�� ��) ������ �����ڿ� ���� ��츸 ������ش�*/ 
					while(!operators.empty()&&priority(operators.top()) == priority(equation[i])){
						cout<<operators.top();
						operators.pop();
					}
					operators.push(equation[i]); 
				}
			}
			//����� �����ڰ� �ƹ��͵� ���� ���
			else{
				operators.push(equation[i]);
			}
		}
		//�ǿ������� ���
		else cout<<equation[i];
	}
	while(!operators.empty()){
		cout<<operators.top();
		operators.pop();
	}
}
