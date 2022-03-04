#include <iostream>
#define ORIGINAL 0
#define DELETE 1

using namespace std;

int main(){
	int n, answer = -1001, arr[100001]={},dp[100001][2];
	//�Է�
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	//0��° �迭�� ��� ���ϹǷ� �ּҰ����� �۰� �ʱ�ȭ
	dp[0][ORIGINAL] = dp[0][DELETE] = -1001;
	//��� �迭 �� Ȯ��
	for(int i = 1; i <= n; i++){
		//�迭�� ������ �ʴ� ���
		dp[i][ORIGINAL] = max(arr[i]+dp[i-1][ORIGINAL], arr[i]);
		//�̹��� ����� ���� ������ ������ ��� �� �ִ밪 ����
		dp[i][DELETE] = max(dp[i-1][ORIGINAL], dp[i-1][DELETE]+arr[i]);
		//���±��� ���� ���� �̹��� ���� ������ �� ���� �������� �� ���� �ִ밪
		answer = max(answer,max(dp[i][ORIGINAL], dp[i][DELETE]));
	}
	//���
	cout<<answer;
}
