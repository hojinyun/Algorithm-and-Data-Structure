#include <iostream>

using namespace std;

int main(){
	int n, first, second, multiple;
	//입력 
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> first;
		cin >> second;
		multiple = first*second;
		//유클리드 호제법으로 최대공약수를 구함 
		while(second%first){
			int temp = second;
			second = first;
			first = temp%first;
		}
		//최소공배수=두수의 곱/최대공약수
		cout << multiple/first <<'\n';
	}
}
