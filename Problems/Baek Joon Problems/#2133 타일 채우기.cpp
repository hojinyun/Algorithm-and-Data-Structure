#include <iostream>

using namespace std;

int main(){
	int n, dp[31] = {};
	//입력
	cin >> n;
	//Base case 값 초기화
	dp[0]=1;
	dp[2]=3;
	//4에서부터 n까지 바텀업 방식으로 경우의 수 쌓아 올라감
	for(int i = 4; i <= n; i+=2){
		dp[i] = 3*dp[i-2]; //2칸이 추가 된 경우
		for(int j = 4; j <= i; j+=2){
			dp[i]+=2*dp[i-j]; //4, 6, 8, .... n칸이 추가 된 경우
		}
	}
	//출력
	cout<<dp[n];
}