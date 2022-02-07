#include <iostream>

using namespace std;

int main(){
	int x;
	//입력  
	cin >> x;
	//x 인덱스까지의 배열 생성 
	int dp[x+1] = {0, 0};
	//바텀 업 방식의 다이나믹 프로그래밍 구현
	for(int i = 2; i <= x; i++){ //바텀 업은 for문을 사용
		//입력값에서 1을 빼는 경우 저장
		dp[i] = dp[i-1]+1;
		//입력값에서 2를 나누는 경우와 비교하여 최소값 저장
		if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2]+1);
		//입력값에서 3을 나누는 경우와 비교하여 최소값 저장
		if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3]+1);
	}
	//출력 
	cout << dp[x];
}
