#include <iostream>

using namespace std;

int main(){
	int n, answer=0, dp[501][501]={};
	//�Է�
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){ //n��° �ٸ��� n���� �Է°��� �����Ƿ� i���� ����
			cin >> dp[i][j];
			//���� �� �ΰ� �߿� ū ���� �� �� ���� ���� ���Ѵ�
			dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
		}
	}
	//��� ���� �� �ִ��� ��� ����
	for(int i = 1; i <= n; i++) answer = max(dp[n][i], answer);
	//���
	cout << answer;
}
