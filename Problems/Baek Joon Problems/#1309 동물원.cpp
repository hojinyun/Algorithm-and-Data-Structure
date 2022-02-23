#include <iostream>
#define NONE 0
#define LEFT 1
#define RIGHT 2
#define MOD 9901

using namespace std;

int main(){
	int n, dp[100001][3]={};
	//입력
	cin >> n;
	//배열의 길이가 1일 때는 세가지의 경우의 수가 1개씩 있으므로 1로 초기화
	//*배열의 시작을 0으로 할 수도 있지만 이해하기 편하게 하기 위해 1부터 시작하였다
	dp[1][NONE]=dp[1][LEFT]=dp[1][RIGHT]=1;
	//2부터 n까지 모든 이전의 경우의 수를 합하여 바텀업 방식으로 쌓아 올린다
	for(int i = 2; i <= n; i++){
		//사자가 없는 경우 이전 줄에 있는 모든 경우를 더할 수 있음
		dp[i][NONE] = (dp[i-1][NONE]+dp[i-1][LEFT]+dp[i-1][RIGHT])%MOD; 
		//사자가 왼쪽에 있는 경우 이전 줄에 사자가 왼쪽에 있는 경우를 제외하고 더해준다
		dp[i][LEFT] = (dp[i-1][NONE]+dp[i-1][RIGHT])%MOD; //사자가 왼쪽에 있는 경우
		//사자가 오른쪽에 있는 경우 이전 줄에 사자가 오른쪽에 있는 경우를 제외하고 더해준다
		dp[i][RIGHT] = (dp[i-1][NONE]+dp[i-1][LEFT])%MOD;
	}
	//모든 경우의 수를 합한 뒤 출력
	cout<<(dp[n][NONE]+dp[n][LEFT]+dp[n][RIGHT])%MOD;
}