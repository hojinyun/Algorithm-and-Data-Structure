#include <iostream>

using namespace std;

int n, k;
	
int main(){
	//입력
	cin >> n >> k;
	//k * n 크기를 가진 2차원 배열 생성
	int dp[k+1][n+1]={}; //0번째 모든 배열 0으로 만들기 위해 모든 값 0으로 초기화
	for(int i = 0; i <= n; i++) dp[1][i] = 1; //숫자가 1인 경우의 수는 자기 자신 한개이므로 1로 초기화
	for(int i = 0; i <= k; i++) dp[i][1] = i; //합이 1인 경우는 0 여러개와 1로 이루어지므로 배열의 인덱스로 초기화
	//2차원 배열을 모두 확인
	for(int i = 2; i <= k; i++){
		for(int j = 2; j <= n; j++){
			//합은 같지만 개수가 1이 적은 경우의 수 + 합이 1적지만 개수가 같은 경우의 수
			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000000;
		}
	}
	//출력
	cout <<dp[k][n];
}
/*
#include <iostream>
using namespace std;

int main(){
	int n, k;
	//입력
	cin >> n >> k;
	//k * n 크기를 가진 2차원 배열 생성
	int dp[k+1][n+1]={}; //0번째 모든 배열 0으로 만들기 위해 모든 값 0으로 초기화
	for(int i = 0; i <= n; i++) dp[1][i] = 1; 
	//2개인 경우의 부터 k개인 경우까지 모든 경우의 수 배열에 저장
	for(int i = 2; i <= k; i++){
		//합이 1인 경우부터 n인 경우까지 모든 경우의 수 배열에 저장
		for(int j = 1; j <= n; j++){
			//현재 배열은 정수 개수가 한개 적을 때의 1부터 현재 값까지의 합 +1 이다
			for(int l = 1; l <=j; l++){
				dp[i][j]=(dp[i][j]+dp[i-1][l])%1000000000;
			}
			//위에서 말한 +1
			dp[i][j]++;
		}
	}
	//출력
	cout <<dp[k][n];
}
*/
