#include <iostream>

using namespace std;

int d[1001]; //���Ҿ��ΰ�� = {0,1,2}

//ž�ٿ� ����� ��� �Լ�
int dp(int n){
	if(n==1) return 1; //1ĭ�� ��� ����� �� 1��
	if(n==2) return 2; //2ĭ�� ��� ����� �� 2��
	if(d[n]) return d[n]; //�̹� ���� ������ ��� �迭���� ã�ƿ�
	return d[n] = (dp(n-1)+dp(n-2))%10007; //��ĭ�� ���� ��ĭ�� ���� ���� ����� �� Ȯ��

}

int main(void){
	int n;
	//�Է�
	cin >> n;

	/* ���Ҿ� ���
	for(int i = 3; i<=n; i++){
		d[i] = (d[i-1]+d[i-2])%10007; //��ĭ�� ���� ��ĭ�� ���� ���� ����� �� Ȯ��
	}
	cout<<d[n];
	*/

	//���
	cout<<dp(n);
	
}
