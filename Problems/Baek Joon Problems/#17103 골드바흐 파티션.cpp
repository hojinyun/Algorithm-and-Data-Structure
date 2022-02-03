#include <iostream>
#define MAX 1000001

using namespace std;

//0과 1은 소수가 아니므로 false로 초기화 
bool isPrime[MAX] = {false, false};

int main(){
	int n, number, counter = 0;
	//입력 
	cin >> n;
	//에라토스테네스의 체
	//배열값 모두 true로 초기화 
	for(int i = 2; i < MAX; i++) isPrime[i] = true;
	//배수인 경우에 false로 변환 
	for(int i = 2; i < MAX; i++){
		if(isPrime[i] == false) continue;
		for(int j = i+i; j < MAX; j+=i) isPrime[j] = false;
	}
	//합하여 입력한 수가 나오는 소수가 있을 때 마다 카운터를 올린다 
	for(int i = 0; i < n; i++){
		cin >> number;
		for(int j = 2; j <= number/2;j++){
			if(isPrime[j] && isPrime[number-j]) counter++;
		}
		//정답 출력 
		cout << counter << '\n';
		counter = 0; //counter 값 초기화 
	}
}
