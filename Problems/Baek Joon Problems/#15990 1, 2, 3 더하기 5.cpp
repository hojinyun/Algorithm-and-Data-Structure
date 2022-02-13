#include <iostream>

using namespace std;

//다이나믹 프로그래밍 배열 생성 및 초기화
long long d[100001][4]={};

int main(){
	int n;
	//입력
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		//Base case를 설정
		d[1][1] = d[2][2] = d[3][1] = d[3][2] = d[3][3] = 1;
		//모든 경우의 d[j][k]에서 j는 만들려고 하는 합, k는 끝에 자리
		for(int j = 4; j <= temp; j++){
			// = 기준 오른쪽 부분은 끝자리를 제외하고 남은 값들의 가능 조합의 합
			d[j][1] = (d[j-1][2]+d[j-1][3])%1000000009; 
			d[j][2] = (d[j-2][1]+d[j-2][3])%1000000009;
			d[j][3] = (d[j-3][1]+d[j-3][2])%1000000009;
 		}
		//출력
		cout << (d[temp][1] + d[temp][2] + d[temp][3])%1000000009<<'\n';
	}
}
