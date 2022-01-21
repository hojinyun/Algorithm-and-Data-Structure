#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n;
	stack<double> s;
	string equation;
	
	//�Է� 
	cin >> n;
	cin.ignore();
	getline(cin, equation);
	double numbers[n];
	for(int i = 0; i < n; i++){
		cin >> numbers[i];	
	}
	for(int i = 0; i < equation.size(); i++){
		//�������� ��� 
		if(equation[i] == '+'||equation[i] == '-'||equation[i] == '*'||equation[i] == '/'){
			double top = s.top();
			s.pop();
			double second_top = s.top();
			s.pop();
			if(equation[i] == '+') s.push(second_top+top);
			else if(equation[i] == '-') s.push(second_top-top);
			else if(equation[i] == '*') s.push(second_top*top);
			else if(equation[i] == '/') s.push(second_top/top);
		}
		//�ǿ������� ��� 
		else{
			s.push(numbers[equation[i]-'A']); //���ĺ����� ���� �ֱ� ������ Index�� ��ȯ 
		}
	}
	//�Ҽ� �ι�° �ڸ����� ���
	printf("%0.2f", s.top()); 
    //cout.precision(2);
    //cout << fixed << s.top();
}
