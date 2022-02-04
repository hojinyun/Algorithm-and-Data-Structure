#include <iostream>
#include <stack>

using namespace std;

int main(){
	int number, n;
	stack<char> answer;
	//입력 
	cin >> number >> n;
	//진법 변환 구현 
	while(number > 0) {
		//나머지가 10이상인 경우 스택에 알파벳 push(11진법 이상인 경우) 
		if(number%n >= 10) answer.push((char)('A'+number%n-10));
		//나머지가 9이하인 경우 나머지인 숫자값 push(10진법 이하인 경우)
		else answer.push((char)(number%n+'0'));
		//숫자를 반내림으로 나누어 줌 
		number /= n;
	}
	//출력 
	while(!answer.empty()){
		cout<<answer.top();
		answer.pop();
	}
}
