#include <iostream>

using namespace std;

int main(){
	int n, dp[10001][3]={};
	//입력
	cin >> n;
	//포도주 양을 더해야 하므로 모든 잔의 번호마다 포도주 양 배열에 저장
	for(int i = 1; i <= n; i++){
		int temp;
		cin >> temp;
		for(int j = 0; j < 3; j++)	dp[i][j] = temp;
	}
	//3가지 경우로 나누어 각 경우마다 맞는 연산 실행
	for(int i = 1; i <= n; i++){
		//이번에 아무 포도주도 안마시는 경우 이전의 모든 경우 중 최대값 선택
		dp[i][0] = max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
		//이번에 한잔 마시는 경우 전에 안마셨을 때의 최대 포도주 양에 현재 양 더함
		dp[i][1] += dp[i-1][0];
		//전에 마셨고 이번에 한잔 더 마시는 경우 전에 경우에 마신 양에 현재 양 더함
		dp[i][2] += dp[i-1][1];
	}
	//3가지 경우 중 최대값 출력
	cout<<max(max(dp[n][0],dp[n][1]),dp[n][2]);
}
