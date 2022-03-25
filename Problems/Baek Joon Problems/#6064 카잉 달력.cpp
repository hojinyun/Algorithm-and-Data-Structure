#include <iostream>

using namespace std;

int lcm(int a, int b){
	//큰 수 항상 a로 오도록하기
	int lcm, original_a = a, original_b = b;
	if(a<b){
		int temp = a;
		a = b;
		b = temp;
	}
	//최대공약수 구하기
	while(a%b!=0){
		int temp = a;
		a = b;
		b = temp%b;
	}
	//최소공배수 구하기
  lcm = original_a*original_b/b;
	return lcm;
}

int main(){
	int num_years, M, N, x, y;
	//입력
	cin >> num_years;
	for(int i = 0; i < num_years; i++){
		cin >> M >> N >> x >> y;
		//종말의 해를 구하기 위해 M, N의 최소공배수 계산
		int max = lcm(M, N); 
		//x를 M만큼 더하여 가능한 모든 경우 x가 나올 수 있는 모든 경우의 수 고려
		for(x; x<=max; x+=M){
			//x가 현재 구하는 년도라고 생각하면 편하다
			//N만큼 나누어 떨어지면 y = N이 가능하므로 N으로 y와 비교 아닐경우 나머지를 y와 비교
			if(((x%N==0) ? N : x%N)==y){ 
				cout<<x<<'\n';
				break;
			} 
		}
		//구한 년도가 범위 밖일 경우 -1 출력
		if(x>max) cout<< -1 <<'\n';
	}
}