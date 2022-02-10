#include <iostream>

using namespace std;

int d[12] = {1, 1, 2}; //Base case n이 0, 1, 2일때 1, 1, 2

int main(){
	int n;
	//입력
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		//입력
		cin >> temp;
		//3부터 시작하여 입력 받은 값까지 모든 경우의 수 쌓아올림
		for(int j = 3; j <= temp; j++){
			d[j] = d[j-1]+d[j-2]+d[j-3]; //전, 전전, 전전전의 값들을 더하면 현재 값이 나온다
		}
		//출력
		cout<<d[temp]<<endl;
	}
}
