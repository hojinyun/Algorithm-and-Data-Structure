#include <iostream>

using namespace std;

int main(){
	int n;
	//입력
	cin >> n;
	//d, price 배열 초기화
	int price[n+1], d[n+1] = {0};
	for(int i = 1; i <= n; i++) cin >> price[i];
	for(int i = 1; i <= n; i++) d[i]=10000;
	
	//1인 경우의 최솟값부터 구함
	for(int i = 1; i <= n; i++){
	//현재 i 이전에 저장 된 모든 최솟값과 해당 되는 가격을 다 더해보고 최소값을 저장
		for(int j = 1; j <= i; j++){
			d[i] = min(d[i], d[i-j]+price[j]);
		}
	}
	//출력
	cout << d[n];
}
