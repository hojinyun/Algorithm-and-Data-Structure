#include <iostream>

using namespace std;

int main(){
	int n, answer = 0, arr[1000], dp[1000]={};
	//입력
	cin >> n;
	for(int i = 0; i < n; i++){
		int max_length = 0; //이전 최대 길이 없애기 위해 0으로 초기화
		cin >> arr[i];
		//이전 값을 확인하기 위한 for문
		for(int j = 0; j < i; j++){
			//자신 이전에 있는 수 중 자기보다 큰 수 중에 최대 길이를 기록
			if(arr[i] < arr[j]) max_length = max(max_length, dp[j]);
		}
		dp[i] = max_length+1; //기록한 최대 길이에 자기 자신도 포함 되므로 1을 더해준다.
		answer = max(answer, dp[i]); //배열에 저장 된 값중 최대값 기록ㄴ
	}
	//출력
	cout << answer;
}