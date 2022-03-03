#include <iostream>
#define ORIGINAL 0
#define DELETE 1

using namespace std;

int main(){
	int n, answer = -1001, arr[100001]={},dp[100001][2];
	//입력
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	//0번째 배열은 사용 안하므로 최소값보다 작게 초기화
	dp[0][ORIGINAL] = dp[0][DELETE] = -1001;
	//모든 배열 값 확인
	for(int i = 1; i <= n; i++){
		//배열을 지우지 않는 경우
		dp[i][ORIGINAL] = max(arr[i]+dp[i-1][ORIGINAL], arr[i]);
		//이번에 지우는 경우와 이전에 지웠을 경우 중 최대값 저장
		dp[i][DELETE] = max(dp[i-1][ORIGINAL], dp[i-1][DELETE]+arr[i]);
		//여태까지 나온 값과 이번에 나온 지웠을 때 값과 안지웠을 때 값의 최대값
		answer = max(answer,max(dp[i][ORIGINAL], dp[i][DELETE]));
	}
	//출력
	cout<<answer;
}
