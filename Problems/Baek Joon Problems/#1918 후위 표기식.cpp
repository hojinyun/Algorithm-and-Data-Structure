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
	//입력
	getline(cin, equation);
	for(int i = 0; i < equation.size(); i++){
		//연산자인 경우
		if(equation[i]=='+'||equation[i]=='-'||equation[i]=='*'
				||equation[i]=='/'||equation[i]=='('||equation[i]==')'){
			//연산자가 있는 경우 
			if(!operators.empty()){
				//괄호가 끝나므로 그 사이에 있는 연산자 모두 출력 
				if(equation[i] == ')'){
					while(operators.top() != '('){
						cout<<operators.top();
						operators.pop();
					}
					operators.pop();
				}
				//새로 들어오는 연산자가 우선순위가 높은 경우
			  //operators.top()이 '('일때 priority가 작아도 다음 연산자가 들어올 수 있도록 함
				else if(priority(operators.top()) < priority(equation[i])||operators.top()=='('){
					operators.push(equation[i]);
				}
				//새로 들어오는 연산자가 우선순위가 낮거나 같은 경우
				else{
					cout<<operators.top();
					operators.pop();
					/*한번 pop을 한 이후 다음 operator는 pop한 operator와 같은 순위일 수가 없으므로
						(같은 크기면 전에 이미 pop 됐어야 함) 들어오는 연산자와 같은 경우만 고려해준다*/ 
					while(!operators.empty()&&priority(operators.top()) == priority(equation[i])){
						cout<<operators.top();
						operators.pop();
					}
					operators.push(equation[i]); 
				}
			}
			//저장된 연산자가 아무것도 없는 경우
			else{
				operators.push(equation[i]);
			}
		}
		//피연산자인 경우
		else cout<<equation[i];
	}
	while(!operators.empty()){
		cout<<operators.top();
		operators.pop();
	}
}
