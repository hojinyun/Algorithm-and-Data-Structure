#include <iostream>

using namespace std;

int main(){
	int n;
	//�Է�
	cin >> n;
	//d, price �迭 �ʱ�ȭ
	int price[n+1], d[n+1] = {0};
	for(int i = 1; i <= n; i++) cin >> price[i];
	for(int i = 1; i <= n; i++) d[i]=10000;
	
	//1�� ����� �ּڰ����� ����
	for(int i = 1; i <= n; i++){
	//���� i ������ ���� �� ��� �ּڰ��� �ش� �Ǵ� ������ �� ���غ��� �ּҰ��� ����
		for(int j = 1; j <= i; j++){
			d[i] = min(d[i], d[i-j]+price[j]);
		}
	}
	//���
	cout << d[n];
}
