#include <iostream>

using namespace std;

int main(){
	string numbers[4];
	long long answer = 0;
	//입력 
	for(int i=0; i < 4; i++){
		cin >> numbers[i];
	}
	//1번째 2번째 숫자 합치고 저장 
	answer += stoll(numbers[0]+numbers[1]);
	//3번째 4번째 숫자 합치고 더 앞에 합친 값에 더 해주기 
	answer += stoll(numbers[2]+numbers[3]);
	//출력 
	cout<<answer;
}
