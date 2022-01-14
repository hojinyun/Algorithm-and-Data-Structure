#include <iostream>
#include <stack>
#define LEFT 0
#define RIGHT 1

using namespace std;

int main(){
	int n;
	cin >> n;
	cin.ignore(); //getline() 빈 줄 불러오기 방지 
	for(int i = 0; i < n; i++){
		string str = "";
		getline(cin, str);
		stack<bool> stack;
		for(int j = 0; j < str.size(); j++){
			//왼쪽 괄호 일 때 스택에 넣기 
			if(str[j] == '(') stack.push(LEFT);
			//오른쪽 괄호 일 때 
			else{
				/*스택이 비었나 같이 확인안하면 undefined behavior 발생*/
				//스택이 안비었고 왼쪽 괄호가 존재하면 제일 위에 있는 왼쪽괄호를 pop 
				if(!stack.empty() && stack.top()==LEFT) stack.pop();
				//스택이 비었거나 제일 위에 있는 괄호가 왼쪽 괄호가 아니면 어짜피 VPS가 아니므로 break 
				else{
					stack.push(RIGHT); //비어있는 스택인 경우에는 아래에서 NO를 받기 위해 RIGHT을 스택에 push 
					break;
				}
			}
		}
		if(stack.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}	
