#include <iostream>
#include <math.h>

using namespace std;

int main(){
	bool isPrime;
	int n, answer = 0;
	//�Է� 
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		isPrime = true; //false�� �ٲ���� ���� �ִ� isPrime�� true�� �ʱ�ȭ
		//������ ��Ʈ �������� ��� ���� ����� �� �� �ִ��� Ȯ�� 
		for(int j = 2; j <= (int)sqrt(temp); j++){
			//����� �ִ� ���(������ �������� ���) 
			if(temp % j == 0){
				isPrime = false;
				break;
			}
		}
		//1�� �Ҽ��� �ƴϹǷ� ���� 
		if(temp!=1 && isPrime) answer++;
	}
	//��� 
	cout << answer;
}
