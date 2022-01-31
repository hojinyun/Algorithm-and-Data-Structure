#include <iostream>

using namespace std;

int main(){
	//최대 값이 100*1,000,000이기 때문에 long long을 써야 됨 
	long long gcd = 0; 
	int n, m;
	//입력 
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> m;
		//m 크기 배열에 저장 
		int numbers[m];
		for(int j = 0; j < m; j++){
			cin >> numbers[j];
		}
		//모든 쌍의 경우를 위한 2중 for문 
		for(int j = 0; j < m; j++){
			for(int k = j+1; k < m; k++){
				//계산을 위한 숫자값 저장 
				int temp, a = numbers[j], b = numbers[k];
				
				//큰 수를 a에 놓기 위한 if문 
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
				gcd += b;
				
			}
		}
		//출력 
		cout << gcd <<'\n'; 
		//정답 값 초기화
		gcd = 0;
	}
}
