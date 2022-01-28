#include <iostream>

using namespace std;

bool prime[1000001] = {false, false}; //0�� 1�� �Ҽ��� �ƴϹǷ� false�� �ʱ�ȭ 

int main(){
	int min, max;
	//�Է� 
	cin >> min >> max;
	//�����佺�׳׽��� ü ���� 
	for(int i = 2; i <= max; i++) prime[i] = true;  //��� �迭 �� true�� �ʱ�ȭ 
	for(int i = 2; i <= max; i++){
		 //�̹� false�� �ٲ� ���� ���� 
		if(prime[i] == false) continue;
		//2���� max���� ��� ��� �ε����� ���� ���� 0���� �ٲ� 
		for(int j = i+i; j <= max; j+=i) prime[j] = false;
	}
	//��� 
	for(int i = min; i <= max; i++){
		//�Ҽ��� ��쿡 �ε��� �� ��� 
		if(prime[i]) cout << i << '\n';
	}
}
