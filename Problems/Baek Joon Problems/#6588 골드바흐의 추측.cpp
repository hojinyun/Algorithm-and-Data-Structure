#include <iostream>
#define MAX 10000001

using namespace std;

bool prime[MAX] = {false, false};

int main(){
	//시간 초과 안되기 위한 코드
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = -1, answer_a = 0, answer_b = 0;
	//에라토스테네스의 체
	for(int i = 2; i < MAX; i++) prime[i] = true;
	for(int i = 2; i < MAX; i++){
		if(prime[i]==false) continue;
		for(int j = i+i; j < MAX; j+=i) prime[j] = false;
	}
	//소수쌍 구하기
	while(n!=0){
		cin >> n;
		if(n==0) break;
		for(int i = 2; i <= n/2; i++){
			if(prime[i] && prime[n-i]){
				answer_a = i;
				answer_b = n-i;
				break;
			}
		}
		//정답이 없을 경우 출력
		if(answer_a == 0) cout <<"Goldbach's conjecture is wrong."<< '\n';
		//정답이 있을 경우 출력
		else cout << n <<" = "<< answer_a << " + " << answer_b << '\n';
		//출력 후 정답 초기화
		answer_a = 0;
		answer_b = 0;
	}
	
}
