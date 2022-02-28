#include <iostream>

using namespace std;

int main(){
	int n, ans = 0, arr[1001], d[1001]={};
	//입력
	cin >> n;
	for(int i = 0; i<n; i++){
		int max_num = 0; //이전 최대 값과 중첩 안되게 최대 값 0으로 초기화
		cin >> arr[i];
		for(int j = 0; j<i; j++){
			//현재 배열보다 작은 값인 경우 그 중 d[]에 저장 된 최대 길이의 값을 기록
			if(arr[j] > arr[i]) max_num = max(max_num, d[j]);
		}
		d[i] = max_num+1; //자기 자신을 포함하므로 최대 길이 +1
		ans = max(ans, d[i]); //전체 입력값 중에 최대 길이를 기록
	}
	//출력
	cout << ans;
}
