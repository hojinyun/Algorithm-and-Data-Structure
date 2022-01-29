#include <iostream>

using namespace std;

int main(){
	int n, answer = 1;
	//입력
	cin >> n;
	//n에서하나씩 빼면서 팩토리얼 계산 
	while(n){ 
		answer *= n;
		n--;
	}
	//출력 
	cout<<answer;
}
