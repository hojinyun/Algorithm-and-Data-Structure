//스택 미사용 
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

//스택 사용 
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
		//s[i] == ')'인 경우
		else{
			//')'에 맞는 짝이 되는 '('를 꺼냄 
			stack.pop();
			//레이저인 경우
			if(s[i-1] == '(') answer += stack.size();
			//레이저가 아닌 막대기의 끝인 경우 
			else answer++;
		}
	}
	cout << answer;
}
