#include <iostream>

using namespace std;

int main(){
	int n;
	//�Է�
	cin >> n;
	//d, price �迭 �ʱ�ȭ
	int price[n+1], d[n+1]={};
	for(int i = 1; i <= n; i++) cin >> price[i];
	
	//1�� ����� �ִ񰪺��� ����
	for(int i = 1; i <= n; i++){
	//���� i ������ ���� �� ��� �ִ񰪰� �ش� �Ǵ� ������ �� ���غ��� �ִ밪�� ����
		for(int j = 1; j <= i; j++){
			d[i] = max(d[i], d[i-j]+price[j]);
		}
	//���
	cout << d[n];
}
