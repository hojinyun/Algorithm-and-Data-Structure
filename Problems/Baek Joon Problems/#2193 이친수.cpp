#include <iostream>

using namespace std;

int main(){
	int n;
	long long d[91] = {0, 1, 1};
	//입력 
	cin >> n;
	//피보나치 수열
	for(int i = 3; i <= n; i++){
		d[i] = d[i-1]+d[i-2];
	}
	//출력 
	cout<<d[n];
}

/* 끝자리 기록하여 푸는 방식 
#include <iostream>

using namespace std;
int main(){
	int n;
	long long d[91][2];
	cin >> n;
	//배열 초기화(첫째자리가 0인 경우 제외) 
	d[1][0]=d[2][1]=0;
	d[1][1]=d[2][0]=1;
	
	for(int i = 3; i <= n; i++){
		//끝이 0인 경우 이전 자리가 0 또는 1이면 가능 
		d[i][0] = d[i-1][0]+d[i-1][1];
		//끝이 1인 경우 이전 자리가 0이여야만 가능 
		d[i][1] = d[i-1][0];
	}
	//출력 
	cout<<d[n][0]+d[n][1];
}*/
