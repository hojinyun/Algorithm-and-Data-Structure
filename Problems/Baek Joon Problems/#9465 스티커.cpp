#include <iostream>
#define TOP 0
#define BOTTOM 1
#define NONE 2

using namespace std;

int main(){
	int t, n;
	//�Է�
	cin >> t;
	for(int i = 0; i < t; i++){
		int dp[3][100000]={}; //t�� 2�̻��� �� ���� ����� �Ȱ�ġ�� dp �迭 �ʱ�ȭ
		cin >> n;
		//���߿� ���ϱ� ���ؼ� ��� �Է°� dp �迭�� ����
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < n; k++) cin >> dp[j][k];
		}
		//�ִ� �� �� �������� 3���� ���(�Ȱ� ���, �� �� ���, �Ʒ� �� ���)�� ������ �迭�� ����
		for(int j = 1; j < n; j++){
			//�Ȱ��� ��� ���� ������ ���� ��� ���� ������ �� �� �ִ븦 ����
			dp[NONE][j] = max(max(dp[NONE][j-1], dp[TOP][j-1]), dp[BOTTOM][j-1]);
			//���� ���� ���� ���� ���� ���� ��츦 �����ϰ� �ִ밪�� �ڽŰ� �� ���ش�
			dp[TOP][j] += max(dp[NONE][j-1], dp[BOTTOM][j-1]);
			//�Ʒ��� ���� ���� ���� �Ʒ��� ���� ��츦 �����ϰ� �ִ밪�� �ڽŰ� �� ���ش�
			dp[BOTTOM][j] += max(dp[NONE][j-1], dp[TOP][j-1]);
		}
		//������ ��� �߿� �ִ밪�� ���
		cout<<max(max(dp[NONE][n-1],dp[TOP][n-1]),dp[BOTTOM][n-1])<<'\n';
	}
}
