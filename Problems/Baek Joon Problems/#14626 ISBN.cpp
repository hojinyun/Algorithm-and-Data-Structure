#include <iostream>

using namespace std;

int main(void){
	char numbersChar[14];
	int erasedIndex, answer, sum = 0, numbersInt[14];
	
	for(int i = 1; i < 14; i++){
		cin >> numbersChar[i];
		if(numbersChar[i] == '*'){
			erasedIndex = i;
		}
	}
	
	//숫자 input 변환 및 합 구하기 
	for(int i = 1; i < 14; i++){
		if(i != erasedIndex){
			//홀수 
			if(i%2==1){
				numbersInt[i] = (int)numbersChar[i]-'0';
				if(i==13){
					break;
				}
			} 
			//짝수
			else if(i%2==0){
				numbersInt[i] = 3*((int)numbersChar[i]-'0');
			} 
		}
		else{
			continue;
		}
		sum += numbersInt[i];
	}

	//알맞는 숫자 찾기 
	//홀수 
	if(erasedIndex%2==1){
		for(int i = 0; i < 10; i++){
			if((sum+i+numbersInt[13])%10==0){
				answer = i;
			}
		}
	} 
	//짝수
	else if(erasedIndex%2==0){
		for(int i = 0; i < 10; i++){
			if((sum+3*i+numbersInt[13])%10==0){
				answer = i;
			}
		}
	} 
	cout << answer;
}
