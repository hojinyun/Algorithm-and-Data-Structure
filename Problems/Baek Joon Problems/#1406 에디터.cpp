#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n;
	stack<char> left, right;
	string s = "";
	
	getline(cin, s);
	cin >> n;

	//모든 문자열들 왼쪽 스택에 넣기
	for(int i = 0; i < s.size(); i++) left.push(s[i]);
	
	for(int i = 0; i < n; i++){
		char temp;
		cin >> temp;
		
		if(temp == 'L'){
			if(!left.empty()){
				//왼쪽으로 넘어가지 왼쪽에 있던 값이 오른쪽으로 스택으로 가야 됨
				right.push(left.top());
				left.pop();
			}
		}
		else if(temp == 'D'){
			//위의 경우와 반대
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

	//스택 사이즈가 줄어드는 것을 방지하기 위해 값을 저장
	int left_size = left.size();
	//출력 시 편하게 모든 문자들 오른쪽 스택으로 옮기기
	for(int i = 0; i < left_size; i++){
		right.push(left.top());
		left.pop();
	}
	
	//위와 마찬가지로 스택 사이즈가 줄어드는 것을 방지하기 위해 값을 저장
	int right_size = right.size();
	for(int i = 0; i < right_size; i++){
		cout << right.top();
		right.pop();
	}
}
