#include <iostream>

using namespace std;

int d[12] = {1, 1, 2}; //Base case n�� 0, 1, 2�϶� 1, 1, 2

int main(){
	int n;
	//�Է�
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		//�Է�
		cin >> temp;
		//3���� �����Ͽ� �Է� ���� ������ ��� ����� �� �׾ƿø�
		for(int j = 3; j <= temp; j++){
			d[j] = d[j-1]+d[j-2]+d[j-3]; //��, ����, �������� ������ ���ϸ� ���� ���� ���´�
		}
		//���
		cout<<d[temp]<<endl;
	}
}
