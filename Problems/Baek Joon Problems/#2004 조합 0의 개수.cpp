#include <iostream>

using namespace std;

int main(){
	long long n, m, num_two = 0, num_five = 0, two_multiple=2, five_multiple = 5;
	//입력 
	cin >> n >> m;
	//---------5의 개수--------------
	//n에 있는 5의 개수 더해주기
	while(n/five_multiple){
		num_five+=n/five_multiple;
		five_multiple*=5;
	}
	//5의 배수 초기화
	five_multiple = 5;
	//m에 있는 5의 개수 빼주기
	while(m/five_multiple){
		num_five-=m/five_multiple;
		five_multiple*=5;
	}
	//5의 배수 초기화
	five_multiple = 5;
	//n-m에 있는 5의 개수 빼주기
	while((n-m)/five_multiple){
		num_five-=(n-m)/five_multiple;
		five_multiple*=5;
	}
	//---------2의 개수--------------
	//n에 있는 5의 개수 더해주기
	while(n/two_multiple){
		num_two+=n/two_multiple;
		two_multiple*=2;
	}
	//2의 배수 초기화
	two_multiple = 2;
	//m에 있는 2의 개수 빼주기
	while(m/two_multiple){
		num_two-=m/two_multiple;
		two_multiple*=2;
	}
	//2의 배수 초기화
	two_multiple = 2;
	//n-m에 있는 2의 개수 빼주기
	while((n-m)/two_multiple){
		num_two-=(n-m)/two_multiple;
		two_multiple*=2;
	}
	//두개의 값중 최솟값 출력
	cout << min(num_two, num_five); 
}
