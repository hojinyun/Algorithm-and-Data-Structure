#include <iostream>

using namespace std;

int main(){
	int n, i = 1, answer=0;
	//입력
	cin >> n;
	//10의 배수 i가 입력값보다 클때까지 연산 실행
	while(i <= n){
		//각 자리수를 가지고 있는 수 만큼 더한다 ex) 15 = 일의 자리수 15 + 십의 자리수 6
		answer+=n-i+1;
		i*=10;
	}
	//출력
	cout<<answer;
}