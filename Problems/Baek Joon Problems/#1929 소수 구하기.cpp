#include <iostream>

using namespace std;

bool prime[1000001] = {false, false}; //0과 1은 소수가 아니므로 false로 초기화 

int main(){
	int min, max;
	//입력 
	cin >> min >> max;
	//에라토스테네스의 체 구현 
	for(int i = 2; i <= max; i++) prime[i] = true;  //모든 배열 값 true로 초기화 
	for(int i = 2; i <= max; i++){
		 //이미 false로 바뀐 수는 무시 
		if(prime[i] == false) continue;
		//2부터 max까지 모든 배수 인덱스를 가진 값을 0으로 바꿈 
		for(int j = i+i; j <= max; j+=i) prime[j] = false;
	}
	//출력 
	for(int i = min; i <= max; i++){
		//소수인 경우에 인덱스 값 출력 
		if(prime[i]) cout << i << '\n';
	}
}
