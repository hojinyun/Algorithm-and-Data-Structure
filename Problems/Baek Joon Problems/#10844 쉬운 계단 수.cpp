#include <iostream>
#define MOD 1000000000

using namespace std;

int main(){
	int n, answer = 0;
	//입력 
	cin >> n;
	long long d[n+1][10];
	//Base case 초기화 
	for(int i = 0; i <= 9; i++){
		if(i==0) d[1][i] = 0;
		else d[1][i] = 1;
	}
	//2부터 n까지 모든 경우의 수 구함 
	for(int i = 2; i <= n; i++){
		//끝에 자리마다 경우의 수 기록 
		for(int j = 0; j <= 9; j++){
			if(j == 0) d[i][j] = (d[i-1][j+1])%MOD; //끝에 자리가 1인 경우 
			else if(j == 9) d[i][j] = (d[i-1][j-1])%MOD; //끝에 자리가 9인 경우 
			else d[i][j] = (d[i-1][j-1] + d[i-1][j+1])%MOD; //나머지 경우 
		} 
	}
	//정답 합산 
	for(int i = 0; i <= 9; i++) answer = (answer+d[n][i])%MOD;
	//출력 
	cout << answer;
}
