#include <iostream>
#define MAX 1000001

using namespace std;

//0�� 1�� �Ҽ��� �ƴϹǷ� false�� �ʱ�ȭ 
bool isPrime[MAX] = {false, false};

int main(){
	int n, number, counter = 0;
	//�Է� 
	cin >> n;
	//�����佺�׳׽��� ü
	//�迭�� ��� true�� �ʱ�ȭ 
	for(int i = 2; i < MAX; i++) isPrime[i] = true;
	//����� ��쿡 false�� ��ȯ 
	for(int i = 2; i < MAX; i++){
		if(isPrime[i] == false) continue;
		for(int j = i+i; j < MAX; j+=i) isPrime[j] = false;
	}
	//���Ͽ� �Է��� ���� ������ �Ҽ��� ���� �� ���� ī���͸� �ø��� 
	for(int i = 0; i < n; i++){
		cin >> number;
		for(int j = 2; j <= number/2;j++){
			if(isPrime[j] && isPrime[number-j]) counter++;
		}
		//���� ��� 
		cout << counter << '\n';
		counter = 0; //counter �� �ʱ�ȭ 
	}
}
