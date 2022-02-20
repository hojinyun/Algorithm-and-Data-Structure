#include <iostream>

using namespace std;
	
int n, d[100001];

int main(){
	//입력
	cin >> n;
	//모든 값을 1^2의 합으로 나타냈을 때의 최대 경우의 수로 초기화
	for(int i = 0; i <=n ; i++) d[i] = i;
	//1부터 n까지 하나씩 최소의 경우 수를 저장하면서 바텀업 방식으로 올라간다
	for(int i=1; i<=n ; i++){
		//가능한 제곱의 수 모두 확인
		for(int j=1; j*j <= i; j++){
			//가능한 제곱의 수 확인 후 최소값 저장
			d[i] = min(d[i], d[i-j*j]+1);
		}
	}
	//출력
	cout<<d[n];
}
