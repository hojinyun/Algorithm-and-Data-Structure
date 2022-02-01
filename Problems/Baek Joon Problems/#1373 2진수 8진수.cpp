#include <iostream>
#include <stack>

using namespace std;

int main(){
	int cnt = 0, temp = 0, multiple = 1;
	stack<int> answer;
	string s;
	//입력
	getline(cin, s);
	//첫번째 자리수부터 시작해야 되므로 s의 최대 크기부터 시작
	for(int i = s.size()-1; i >= 0; i--){
		//첫번째 경우를 제외한 매 3번째 연산마다 스택에 넣고 변수 초기화 
		if(cnt%3 == 0 && i != s.size()-1){
			answer.push(temp);
			temp = 0; 
			multiple = 1;
		} 
		//s[i]를 int값으로 바꿔 2의 n승 연산하여 temp에 더 함 
		temp += (s[i]-'0')*multiple;
		//2의 1승 추가
		multiple *= 2;
		cnt++;
	}
	//연산 끝나고 남은 값 추가 
	answer.push(temp);
	//출력 
	while(!answer.empty()){
		cout<<answer.top();
		answer.pop();
	}
	
}
