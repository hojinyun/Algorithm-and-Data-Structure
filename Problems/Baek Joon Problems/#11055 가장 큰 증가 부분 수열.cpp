#include <iostream>

using namespace std;

int main(){
	int n, answer = 0, dp[1000]={}, arr[1000];
	//입력
	cin >> n;
	for(int i = 0; i < n; i++){
		int max_num = 0; //이전 최대값을 지우기 위해 0으로 선언 및 초기화
		cin >> arr[i];
		for(int j = 0; j < i; j++){
			//자신보다 작은 값 중에 합이 제일 큰 값을 기록
			if(arr[i] > arr[j]) max_num = max(max_num,dp[j]);
		}
		dp[i] = max_num+arr[i]; //기록한 최대 값에 자신의 값을 더해서 배열에 저장
		answer = max(answer, dp[i]); //배열에 저장 된 값중 최대값 기록
	}
	//출력
	cout<<answer;
}
