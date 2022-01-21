#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n;
	stack<double> s;
	string equation;
	
	//입력 
	cin >> n;
	cin.ignore();
	getline(cin, equation);
	double numbers[n];
	for(int i = 0; i < n; i++){
		cin >> numbers[i];	
	}
	for(int i = 0; i < equation.size(); i++){
		//연산자일 경우 
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
		//피연산자일 경우 
		else{
			s.push(numbers[equation[i]-'A']); //알파벳으로 적혀 있기 때문에 Index로 변환 
		}
	}
	//소수 두번째 자리까지 출력
	printf("%0.2f", s.top()); 
    //cout.precision(2);
    //cout << fixed << s.top();
}
