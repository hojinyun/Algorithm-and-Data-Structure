#include <iostream>

using namespace std;

int main(){
	int n, ans = -1001, arr[100000], d[100000];
	//입력 
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	d[0] = arr[0]; //첫번째 배열 값 초기화 
	//자기 자신값 vs 이전 값의 최대값+자기자신 값 중 최대값을 비교 
	for(int i = 0; i < n; i++){
		d[i] = max(d[i-1]+arr[i],arr[i]);
		ans = max(d[i], ans); //기록 된 최대값 중 제일 큰 값 기록 
	}
	//출력 
	cout << ans;
}
