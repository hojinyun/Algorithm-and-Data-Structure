#include <iostream>
#define R 0
#define G 1
#define B 2

using namespace std;

int main(){
	int n;
	//�Է�
	cin >> n;
	long long dp[n][3];
	for(int i = 0; i < 3; i++) cin >> dp[0][i]; //dp[0][#] �� �ʱ�ȭ
	for(int i = 1; i < n; i++){
		cin >> dp[i][R] >> dp[i][G] >> dp[i][B]; //�ڽ��� �� �Է�
		//���� ���� ���� �� �ּ� ���� �ڽŰ� ����
		dp[i][R] += min(dp[i-1][G],dp[i-1][B]);
		dp[i][G] += min(dp[i-1][R],dp[i-1][B]);
		dp[i][B] += min(dp[i-1][R],dp[i-1][G]);
	}
	//���
	cout << min(dp[n-1][R],min(dp[n-1][G], dp[n-1][B]));
}
