#include <iostream>

using namespace std;

int main(){
	int n, ans = -1001, arr[100000], d[100000];
	//�Է� 
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	d[0] = arr[0]; //ù��° �迭 �� �ʱ�ȭ 
	//�ڱ� �ڽŰ� vs ���� ���� �ִ밪+�ڱ��ڽ� �� �� �ִ밪�� �� 
	for(int i = 0; i < n; i++){
		d[i] = max(d[i-1]+arr[i],arr[i]);
		ans = max(d[i], ans); //��� �� �ִ밪 �� ���� ū �� ��� 
	}
	//��� 
	cout << ans;
}
