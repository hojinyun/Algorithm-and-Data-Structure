#include <iostream>

using namespace std;

//���� �Ǵ� �ִ밪�� int�δ� �����ϹǷ� long long���� ���� 
long long d[1000001] = {1, 1, 2}; //�迭�� 0, 1, 2�� ����� �ʱⰪ ����

int main(){
	//�Է�
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		for(int j = 3; j <= temp; j++){
			//���� ���� 1�� �����ְ� ������ ���� 2�� �����ְ� �������� ���� 3�� �����ָ� j�� ���´�
			d[j] = (d[j-1]+d[j-2]+d[j-3])%1000000009; 
		}
		//���
		cout << d[temp] << '\n';
	}
}
