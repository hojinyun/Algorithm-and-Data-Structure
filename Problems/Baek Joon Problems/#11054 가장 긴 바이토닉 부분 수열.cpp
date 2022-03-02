#include <iostream>
#define FORTH 0
#define BACK 1

using namespace std;

int main(){
	int n, answer = 0, arr[1000],dp[1000][2]={};
	//입력 
	cin >> n;
	//앞으로 가면서 커지는 값들의 최대 길이 기록 
	for(int i = 0; i < n; i++){
		int max_num = 0; //이전 최대값 0으로 초기화 
		cin >> arr[i];
		//이전 인덱스 방문 
		for(int j = 0; j < i; j++){
			//이전 인덱스 값 중 자신보다 작은 값 중에서 최대 길이 기록 
			if(arr[i] > arr[j])  max_num = max(max_num, dp[j][FORTH]);
		}
		//최대길이 + 자기자신(1) 더한 뒤 배열에 저장 
		dp[i][FORTH] = max_num+1; 
	}
	//뒤로 돌아가면서 커지는 값들의 최대 길이 기록
	for(int i = n-1; i >= 0; i--){
		int max_num = 0; //이전 최대값 0으로 초기화
		//현재 배열의 오른쪽에 있는 모든 인덱스 방문 
		for(int j = i; j < n; j++){
			//오른쪽 인덱스 중에 자신보다 작은 값 중 최대 길이 기록 
			if(arr[i] > arr[j]) max_num = max(max_num, dp[j][BACK]);
		}
		//최대길이 + 자기자신(1) 더한 뒤 배열에 저장 
		dp[i][BACK] = max_num+1;
		//앞으로 갔을 때의 최대 길이와 거꾸로 돌아왔을 때 최대 길이의 합 중 최대값 
		answer = max(answer, dp[i][FORTH]+dp[i][BACK]);
	}
	cout << answer-1; //자기 자신 중복 제외 
}
