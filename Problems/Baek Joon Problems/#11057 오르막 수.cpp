#include <iostream>

using namespace std;

int main(){
	int n, answer=0, dp[1001][10]={};
	//입력
	cin >> n;
	//길이가 1인 경우 배열 초기화
	for(int i = 0; i < 10; i++) dp[1][i] = 1;
	//길이가 2인 경우부터 n인 경우까지 바텀업 방식으로 계산
	for(int i = 2; i <=n; i++){
		//j는 끝에 자리수를 의미
		for(int j = 0; j < 10; j++){
			//끝에 자리수(j)보다 작거나 같은 값들을 끝자리 인덱스로 갖고 있는 값들의 경우의 수를 모두 합한다
			for(int k = 0; k <= j; k++) dp[i][j]=(dp[i][j]+dp[i-1][k])%10007;
		}
	}
	//끝에 자리수의 경우의 수를 모두합한다
	for(int i = 0; i < 10; i++) answer= (answer+dp[n][i])%10007;
	//출력
	cout << answer;
}