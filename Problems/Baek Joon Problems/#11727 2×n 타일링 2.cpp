#include <iostream>

using namespace std;

int d[1001]; //바텀업인경우 = {0,1,3}

//탑다운 방식의 재귀 함수
int dp(int n){
	if(n==1) return 1; //시작하는 칸이 1칸인 경우 경우의 수 1개
	if(n==2) return 3; //시작하는 칸이 2칸인 경우 경우의 수 3개
	if(d[n]) return d[n]; //이미 값이 존재할 경우 배열에서 찾아옴
	return d[n] = (dp(n-1)+2*dp(n-2))%10007; //한칸인 경우와 두칸인 경우로 나눠 경우의 수 확인

}

int main(void){
	int n;
	//입력
	cin >> n;

	/* 바텀업 방식
	for(int i = 3; i<=n; i++){
		d[i] = (d[i-1]+2*d[i-2])%10007; //한칸인 경우와 두칸인 경우로 나눠 경우의 수 확인
	}
	cout<<d[n];
	*/

	//출력
	cout<<dp(n);
}
