#include <iostream>

using namespace std;

int main(){
	int n, answer = 0, dp[1000]={}, arr[1000];
	//�Է�
	cin >> n;
	for(int i = 0; i < n; i++){
		int max_num = 0; //���� �ִ밪�� ����� ���� 0���� ���� �� �ʱ�ȭ
		cin >> arr[i];
		for(int j = 0; j < i; j++){
			//�ڽź��� ���� �� �߿� ���� ���� ū ���� ���
			if(arr[i] > arr[j]) max_num = max(max_num,dp[j]);
		}
		dp[i] = max_num+arr[i]; //����� �ִ� ���� �ڽ��� ���� ���ؼ� �迭�� ����
		answer = max(answer, dp[i]); //�迭�� ���� �� ���� �ִ밪 ���
	}
	//���
	cout<<answer;
}
