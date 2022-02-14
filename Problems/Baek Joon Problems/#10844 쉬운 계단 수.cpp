#include <iostream>
#define MOD 1000000000

using namespace std;

int main(){
	int n, answer = 0;
	//�Է� 
	cin >> n;
	long long d[n+1][10];
	//Base case �ʱ�ȭ 
	for(int i = 0; i <= 9; i++){
		if(i==0) d[1][i] = 0;
		else d[1][i] = 1;
	}
	//2���� n���� ��� ����� �� ���� 
	for(int i = 2; i <= n; i++){
		//���� �ڸ����� ����� �� ��� 
		for(int j = 0; j <= 9; j++){
			if(j == 0) d[i][j] = (d[i-1][j+1])%MOD; //���� �ڸ��� 1�� ��� 
			else if(j == 9) d[i][j] = (d[i-1][j-1])%MOD; //���� �ڸ��� 9�� ��� 
			else d[i][j] = (d[i-1][j-1] + d[i-1][j+1])%MOD; //������ ��� 
		} 
	}
	//���� �ջ� 
	for(int i = 0; i <= 9; i++) answer = (answer+d[n][i])%MOD;
	//��� 
	cout << answer;
}
