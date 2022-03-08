#include <iostream>

using namespace std;

int main(){
	int E, S, M, year=1;
	//입력
	cin >> E >> S >> M;
	//year가 나머지를 E, S, M으로 가지는 경우 while문 정지
	while(!((year-E)%15==0 && (year-S)%28==0 && (year-M)%19==0)) year++;
	//출력
	cout<<year;
}
