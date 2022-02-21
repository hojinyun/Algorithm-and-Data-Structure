#include <iostream>

using namespace std;

//저장 되는 최대값이 int로는 부족하므로 long long으로 선언 
long long d[1000001] = {1, 1, 2}; //배열이 0, 1, 2인 경우의 초기값 설정

int main(){
	//입력
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		for(int j = 3; j <= temp; j++){
			//전의 값은 1을 더해주고 전전의 값은 2를 더해주고 전전전의 값은 3을 더해주면 j가 나온다
			d[j] = (d[j-1]+d[j-2]+d[j-3])%1000000009; 
		}
		//출력
		cout << d[temp] << '\n';
	}
}
