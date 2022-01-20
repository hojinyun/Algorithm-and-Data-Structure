#include <iostream>
#include <stack>

using namespace std;

int amount[1000000] = {}; // 추가 된 배열 선언

int main(){
	int n;
	stack<int> s, NGF, answer;

	//입력
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		//각 숫자를 인덱스로 나타내고 그 숫자의 개수를 배열에 저장
		amount[temp]++; // 추가 된 배열 연산
		s.push(temp);
	}
	
	while(!s.empty()){
		//제일 오른쪽 숫자가 아닐 때 
		if(!NGF.empty()){
			//오른쪽 숫자가 클 때 
			if(amount[s.top()] < amount[NGF.top()]){ //변경 된 if문
				answer.push(NGF.top());
				NGF.push(s.top());
				s.pop(); 
			}
			//오른쪽 숫자가 작을 때 
			else{
				NGF.pop();
			}
		}
		//제일 오른쪽 숫자여서 NGF가 비어있을 때
		else{
			answer.push(-1);
			NGF.push(s.top());
			s.pop();
		}
	}
	//정답 출력
	for(int i = 0; i < n; i++){
		if(!answer.empty()){
			cout << answer.top() << " ";
			answer.pop();
		}
	}
}
