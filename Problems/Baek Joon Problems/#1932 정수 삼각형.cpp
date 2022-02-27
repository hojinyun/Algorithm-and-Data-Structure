#include <iostream>

using namespace std;

int main(){
	int n, answer=0, dp[501][501]={};
	//입력
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){ //n번째 줄마다 n개의 입력값이 있으므로 i까지 간다
			cin >> dp[i][j];
			//이전 값 두개 중에 큰 값을 고른 뒤 현재 값에 더한다
			dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
		}
	}
	//모든 값들 중 최대인 경우 저장
	for(int i = 1; i <= n; i++) answer = max(dp[n][i], answer);
	//출력
	cout << answer;
}
