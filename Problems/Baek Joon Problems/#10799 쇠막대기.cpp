//���� �̻�� 
/*#include <iostream>

using namespace std;

int main(){
	string s;
	int laser = 0, rod = 0, answer = 0;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] =='(' && s[i+1] == ')'){
			answer += rod;
			i++;
		}
		else if(s[i] == '(') rod++;
		
		//when s[i] = ')'
		else{
			answer += 1;
			rod--;
		}
	}
	cout<<answer;
}*/

//���� ��� 
#include <iostream>
#include <stack>

using namespace std;

int main(){
	int answer = 0; 
	stack<char> stack;
	string s;
	
	cin >> s;
	
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(') stack.push(s[i]);
		//s[i] == ')'�� ���
		else{
			//')'�� �´� ¦�� �Ǵ� '('�� ���� 
			stack.pop();
			//�������� ���
			if(s[i-1] == '(') answer += stack.size();
			//�������� �ƴ� ������� ���� ��� 
			else answer++;
		}
	}
	cout << answer;
}
