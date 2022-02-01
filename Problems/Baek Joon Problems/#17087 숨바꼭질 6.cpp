#include <iostream>

using namespace std;

int main(){
	int num_sib, pos_subin, gcd;
	//�Է� 
	cin >> num_sib >> pos_subin;
	//���� ��ġ ������ ���� ���� �� ũ���� �迭 ���� 
	int pos_sib[num_sib];
	//�迭�� �����̿��� �Ÿ� ���� 
	for(int i = 0; i < num_sib; i++){
		int temp;
		cin >> temp;
		//������ ��ġ���� �� ũ�� ���̳ʽ� �����ֱ� 
		if(pos_subin > temp) pos_sib[i] = pos_subin - temp;
		else pos_sib[i] = -(pos_subin - temp);
	}
	//��Ŭ���� ȣ���� ���� gcd �� �ʱ�ȭ 
	gcd = pos_sib[0];
	//�迭�� ��� ���� �ִ� ����� ���ϱ� 
	for(int i = 1; i < num_sib; i++){
		//���� ���� �ִ� ����� ���� ����Ͽ� �ִ����� �� ���� 
		int temp, a = pos_sib[i], b = gcd;
		//ū ���� a�� ������ �� 
		if(a < b){
			temp = a;
			a = b;
			b = temp;
		}
		//��Ŭ���� ȣ���� 
		while(a%b){
			temp = b;
			b = a%b;
			a = temp;
		}
		gcd = b;
	}
	//��� 
	cout << gcd; 
}
