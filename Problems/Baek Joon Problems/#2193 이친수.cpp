#include <iostream>

using namespace std;

int main(){
	int n;
	long long d[91] = {0, 1, 1};
	//�Է� 
	cin >> n;
	//�Ǻ���ġ ����
	for(int i = 3; i <= n; i++){
		d[i] = d[i-1]+d[i-2];
	}
	//��� 
	cout<<d[n];
}

/* ���ڸ� ����Ͽ� Ǫ�� ��� 
#include <iostream>

using namespace std;
int main(){
	int n;
	long long d[91][2];
	cin >> n;
	//�迭 �ʱ�ȭ(ù°�ڸ��� 0�� ��� ����) 
	d[1][0]=d[2][1]=0;
	d[1][1]=d[2][0]=1;
	
	for(int i = 3; i <= n; i++){
		//���� 0�� ��� ���� �ڸ��� 0 �Ǵ� 1�̸� ���� 
		d[i][0] = d[i-1][0]+d[i-1][1];
		//���� 1�� ��� ���� �ڸ��� 0�̿��߸� ���� 
		d[i][1] = d[i-1][0];
	}
	//��� 
	cout<<d[n][0]+d[n][1];
}*/
