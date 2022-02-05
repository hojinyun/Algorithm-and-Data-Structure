#include <iostream>

using namespace std;

int main(){
	int n;
	//입력 
	cin >> n;
	bool isPrime[n];
	//에라토스테네스의 체 구현
	for(int i=2; i<=n; i++) isPrime[i]=true; //true로 배열 초기화
	for(int i=2; i<=n; i++){
		if(isPrime[i]==false) continue; //이미 false인 값 무시
		for(int j=i+i; j<=n; j+=i) isPrime[j] = false; //배수인 경우 false로 저장 
	}
	//소인수분해
	while(n!=1){
		//2부터 n까지 나눠지는 지 확인 
		for(int i=2; i<=n; i++){ //int i = temp; i값을 저장 해서 시작하는 방법도 있음
			//n이 나누어 떨어지고 소수인 i인 경우 
			if(n%i==0 && isPrime[i]){
				//출력 
				cout<<i<<endl;
				//다음 값을 구하기 위해 n을 i만큼 나누어준다 
				n /= i;
				//다시 2부터 확인하기 위해 for문 탈출 
				break;
			}
		}
	}
}
