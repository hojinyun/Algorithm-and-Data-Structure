#include <iostream>
#define TOP 0
#define BOTTOM 1
#define NONE 2

using namespace std;

int main(){
	int t, n;
	//입력
	cin >> t;
	for(int i = 0; i < t; i++){
		int dp[3][100000]={}; //t가 2이상일 때 이전 값들과 안겹치게 dp 배열 초기화
		cin >> n;
		//나중에 더하기 위해서 모든 입력값 dp 배열에 저장
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < n; k++) cin >> dp[j][k];
		}
		//최대 값 각 세로줄을 3가지 경우(안고른 경우, 위 고른 경우, 아래 고른 경우)로 나누어 배열에 저장
		for(int j = 1; j < n; j++){
			//안고르는 경우 전에 무엇이 오든 상관 없기 때문에 그 중 최대를 고른다
			dp[NONE][j] = max(max(dp[NONE][j-1], dp[TOP][j-1]), dp[BOTTOM][j-1]);
			//위를 고르는 경우는 전에 위가 오는 경우를 제외하고 최대값을 자신과 더 해준다
			dp[TOP][j] += max(dp[NONE][j-1], dp[BOTTOM][j-1]);
			//아래를 고르는 경우는 전에 아래가 오는 경우를 제외하고 최대값을 자신과 더 해준다
			dp[BOTTOM][j] += max(dp[NONE][j-1], dp[TOP][j-1]);
		}
		//세가지 경우 중에 최대값을 출력
		cout<<max(max(dp[NONE][n-1],dp[TOP][n-1]),dp[BOTTOM][n-1])<<'\n';
	}
}
