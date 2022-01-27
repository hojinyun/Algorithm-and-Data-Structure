#include <iostream>

using namespace std;

int main(){
	int first, second, multiple;
	//입력
	cin >> first;
	cin >> second;
	//최소공배수=두수의 곱/최대공약수이므로 나중에 최소공배수 구할 때 필요하다 
	multiple = first*second;
	//유클리드 호제법 구현 
	while(first%second){
		int temp = first;
		first = second;
		second = temp%second;
	}
	//출력 
	cout << second <<'\n'<< multiple/second;
}
