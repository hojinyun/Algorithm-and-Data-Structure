#include <iostream>

using namespace std;

int main(){
	string numbers;
	int n, answer=0;
	//입력 
	cin >> numbers >> n;
	//N진법의 수 10진법으로 변환 
	for(int number: numbers){
		//알파벳인 경우(11진법 이상인 경우) 
		if(number >= 'A' && number <= 'Z') answer = answer*n+(number-'A'+10);
		//숫자인 경우(10진법 이하인 경우) 
		else if(number >= '0' && number <= '9') answer = answer*n+(number-'0');
	}
	//출력 
	cout << answer;
}
