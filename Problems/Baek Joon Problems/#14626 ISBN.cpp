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
	
	//���� input ��ȯ �� �� ���ϱ� 
	for(int i = 1; i < 14; i++){
		if(i != erasedIndex){
			//Ȧ�� 
			if(i%2==1){
				numbersInt[i] = (int)numbersChar[i]-'0';
				if(i==13){
					break;
				}
			} 
			//¦��
			else if(i%2==0){
				numbersInt[i] = 3*((int)numbersChar[i]-'0');
			} 
		}
		else{
			continue;
		}
		sum += numbersInt[i];
	}

	//�˸´� ���� ã�� 
	//Ȧ�� 
	if(erasedIndex%2==1){
		for(int i = 0; i < 10; i++){
			if((sum+i+numbersInt[13])%10==0){
				answer = i;
			}
		}
	} 
	//¦��
	else if(erasedIndex%2==0){
		for(int i = 0; i < 10; i++){
			if((sum+3*i+numbersInt[13])%10==0){
				answer = i;
			}
		}
	} 
	cout << answer;
}
