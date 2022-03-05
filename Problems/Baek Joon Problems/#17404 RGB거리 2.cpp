#include <iostream>
#define R 0
#define G 1
#define B 2

using namespace std;

int main(){
	int n, answer = 1000001, dp[1001][3]={}, arr[1001][3]={};
	//입력
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i][R] >> arr[i][G] >> arr[i][B];
	//처음 시작이 R, G, B인 경우를 나누기 위한 for문
	for(int i = 0; i < 3; i++){
		//현재 시작 색을 제외한 모든 값들을 크게 만들어서 현재 시작 색만 고르도록 하게 초기화
		for(int j = 0; j < 3; j++) dp[1][j] = 1000001;
		dp[1][i] = arr[1][i];
		//색깔마다 최소값이 나오는 경우의 수 저장
		for(int j = 2; j <= n; j++){
			dp[j][R] = min(dp[j-1][G], dp[j-1][B])+arr[j][R];
			dp[j][G] = min(dp[j-1][R], dp[j-1][B])+arr[j][G];
			dp[j][B] = min(dp[j-1][R], dp[j-1][G])+arr[j][B];
		}
		//마지막 색상이 첫번째 색상과 다른 경우만 제외하고 최소값 정답에 저장
		if(i==R) answer = min(answer, min(dp[n][G], dp[n][B]));
		if(i==G) answer = min(answer, min(dp[n][R], dp[n][B]));
		if(i==B) answer = min(answer, min(dp[n][R], dp[n][G]));
	}
	//출력
	cout<<answer;
}