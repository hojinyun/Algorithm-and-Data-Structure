#include <iostream>

using namespace std;

int main(){
	int n, ans = 0, arr[1001], d[1001]={};
	//�Է�
	cin >> n;
	for(int i = 0; i<n; i++){
		int max_num = 0; //���� �ִ� ���� ��ø �ȵǰ� �ִ� �� 0���� �ʱ�ȭ
		cin >> arr[i];
		for(int j = 0; j<i; j++){
			//���� �迭���� ���� ���� ��� �� �� d[]�� ���� �� �ִ� ������ ���� ���
			if(arr[j] > arr[i]) max_num = max(max_num, d[j]);
		}
		d[i] = max_num+1; //�ڱ� �ڽ��� �����ϹǷ� �ִ� ���� +1
		ans = max(ans, d[i]); //��ü �Է°� �߿� �ִ� ���̸� ���
	}
	//���
	cout << ans;
}
