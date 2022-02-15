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
