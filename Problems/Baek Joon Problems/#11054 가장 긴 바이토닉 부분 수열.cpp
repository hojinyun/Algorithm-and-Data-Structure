#include <iostream>
#define FORTH 0
#define BACK 1

using namespace std;

int main(){
	int n, answer = 0, arr[1000],dp[1000][2]={};
	//�Է� 
	cin >> n;
	//������ ���鼭 Ŀ���� ������ �ִ� ���� ��� 
	for(int i = 0; i < n; i++){
		int max_num = 0; //���� �ִ밪 0���� �ʱ�ȭ 
		cin >> arr[i];
		//���� �ε��� �湮 
		for(int j = 0; j < i; j++){
			//���� �ε��� �� �� �ڽź��� ���� �� �߿��� �ִ� ���� ��� 
			if(arr[i] > arr[j])  max_num = max(max_num, dp[j][FORTH]);
		}
		//�ִ���� + �ڱ��ڽ�(1) ���� �� �迭�� ���� 
		dp[i][FORTH] = max_num+1; 
	}
	//�ڷ� ���ư��鼭 Ŀ���� ������ �ִ� ���� ���
	for(int i = n-1; i >= 0; i--){
		int max_num = 0; //���� �ִ밪 0���� �ʱ�ȭ
		//���� �迭�� �����ʿ� �ִ� ��� �ε��� �湮 
		for(int j = i; j < n; j++){
			//������ �ε��� �߿� �ڽź��� ���� �� �� �ִ� ���� ��� 
			if(arr[i] > arr[j]) max_num = max(max_num, dp[j][BACK]);
		}
		//�ִ���� + �ڱ��ڽ�(1) ���� �� �迭�� ���� 
		dp[i][BACK] = max_num+1;
		//������ ���� ���� �ִ� ���̿� �Ųٷ� ���ƿ��� �� �ִ� ������ �� �� �ִ밪 
		answer = max(answer, dp[i][FORTH]+dp[i][BACK]);
	}
	cout << answer-1; //�ڱ� �ڽ� �ߺ� ���� 
}
