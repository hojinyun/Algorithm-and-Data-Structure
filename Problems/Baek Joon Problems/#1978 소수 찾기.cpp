#include <iostream>
#include <math.h>

using namespace std;

int main(){
	bool isPrime;
	int n, answer = 0;
	//입력 
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		isPrime = true; //false로 바뀌었을 수도 있는 isPrime값 true로 초기화
		//숫자의 루트 값까지의 모든 값이 배수가 될 수 있는지 확인 
		for(int j = 2; j <= (int)sqrt(temp); j++){
			//약수가 있는 경우(나누어 떨어지는 경우) 
			if(temp % j == 0){
				isPrime = false;
				break;
			}
		}
		//1은 소수가 아니므로 제외 
		if(temp!=1 && isPrime) answer++;
	}
	//출력 
	cout << answer;
}
