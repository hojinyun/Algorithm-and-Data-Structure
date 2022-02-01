#include <iostream>

using namespace std;

int main(){
	int num_sib, pos_subin, gcd;
	//입력 
	cin >> num_sib >> pos_subin;
	//동생 위치 저장을 위한 동생 수 크기의 배열 생성 
	int pos_sib[num_sib];
	//배열에 수빈이와의 거리 저장 
	for(int i = 0; i < num_sib; i++){
		int temp;
		cin >> temp;
		//수빈이 위치보다 더 크면 마이너스 씌워주기 
		if(pos_subin > temp) pos_sib[i] = pos_subin - temp;
		else pos_sib[i] = -(pos_subin - temp);
	}
	//유클리드 호제를 위해 gcd 값 초기화 
	gcd = pos_sib[0];
	//배열의 모든 값의 최대 공약수 구하기 
	for(int i = 1; i < num_sib; i++){
		//전에 구한 최대 공약수 값과 계산하여 최대공약수 값 갱신 
		int temp, a = pos_sib[i], b = gcd;
		//큰 수가 a에 오도록 함 
		if(a < b){
			temp = a;
			a = b;
			b = temp;
		}
		//유클리드 호제법 
		while(a%b){
			temp = b;
			b = a%b;
			a = temp;
		}
		gcd = b;
	}
	//출력 
	cout << gcd; 
}
