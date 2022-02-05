#include <iostream>
#include <stack>

using namespace std;

int main(){
	int A, B, m, dec=0;
	stack<int> answer;
	//첫번째 줄과 두번째 줄 입력
	cin >> A >> B >> m;
	for(int i = 0; i < m; i++){
		int number;
		cin >> number;
		//A진법에서 10진법으로 변환 
		dec = dec*A+number;
	}
	//10진법에서 B진법으로 변환 
	while(dec > 0) {
		answer.push(dec%B);
		//숫자를 반내림으로 나누어 줌 
		dec /= B;
	}
	//출력
	while(!answer.empty()){
		cout<<answer.top()<<" ";
		answer.pop();
	}
}
