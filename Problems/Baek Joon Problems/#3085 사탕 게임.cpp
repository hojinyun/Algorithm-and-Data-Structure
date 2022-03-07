#include <iostream>

using namespace std;

int n, counter = 1, answer=0;
char board[51][51]={}, temp[51][51]={};

//�Է� ���� board �迭 ���� temp�� ����
void initialize_board(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) temp[i][j] = board[i][j];
	}
}
//���� �ڸ��� ���� ���� �� ���� ������ ã��
void count_horizontal_max(int row, int col){
	//�����ʿ� ���� ���� �ִ� ���
	for(int k = col+1; k <= n; k++){
		//�ٸ� ���� ������ ��� �ٷ� for�� Ż��
		if(temp[row][col]!=temp[row][k]) break;
		counter++;
	}
	//�������� ���� ���� �ִ� ���
	for(int k = col-1; k > 0; k--){
		//�ٸ� ���� ������ ��� �ٷ� for�� Ż��
		if(temp[row][col]!=temp[row][k]) break;
		counter++;
	}
	answer = max(answer,counter);
	counter = 1;
}
//���� �ڸ��� ���� ���� �� ���� ������ ã��
void count_vertical_max(int row, int col) {
	//�Ʒ��� ���� ���� �ִ� ���
	for(int k = row+1; k <= n; k++){
		//�ٸ� ���� ������ ��� �ٷ� for�� Ż��
		if(temp[row][col]!=temp[k][col])break;
		counter++;
	}
	//���� ���� ���� �ִ� ���
	for(int k = row-1; k > 0; k--){
		//�ٸ� ���� ������ ��� �ٷ� for�� Ż��
		if(temp[row][col]!=temp[k][col]) break;
		counter++;
	}
	answer = max(answer,counter);
	counter = 1;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) cin >> board[i][j];
	}
	initialize_board();
	//1���� n���� �¿� ���Ʒ� ��� ���� �� �ٲ㼭 Ȯ�� �غ�
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			//�Ʒ����� �����ϰ� �ٸ� ��� �ٲ�
			if(board[i][j]!=board[i+1][j] && i+1<=n){
				//�迭 �� ��ȯ
				char swap = temp[i][j];
				temp[i][j] = temp[i+1][j];
				temp[i+1][j] = swap;
				count_horizontal_max(i, j); //���� Ȯ�� ���� ���� ���� �ִ� ���� Ȯ��
				count_horizontal_max(i+1, j); //�Ʒ��ٵ� �ٲ������ ���� �ִ� ���� Ȯ��
				count_vertical_max(i,j); //���η� ���� �ٲپ����� ���� Ȯ�� ���� ���� ���� �ִ� ���� Ȯ��
			}
			initialize_board(); //�迭 �� ��ȯ�Ͽ����� ���� �ʱ�ȭ
			//������ ���� �����ϰ� �ٸ� ��� �ٲ�
			if(board[i][j]!=board[i][j+1] && j+1<=n){
				//�迭 �� ��ȯ
				char swap = temp[i][j];
				temp[i][j] = temp[i][j+1];
				temp[i][j+1] = swap;
				count_vertical_max(i,j); //���� Ȯ�� ���� ���� ���� �ִ� ���� Ȯ��
				count_vertical_max(i,j+1); //������ �ٵ� �ٲ������ ���� �ִ� ���� Ȯ��
				count_horizontal_max(i,j); //���η� ���� �ٲپ����� ���� Ȯ�� ���� ���� ���� �ִ� ���� Ȯ��
			}
			initialize_board(); //�迭 �� ��ȯ�Ͽ����� ���� �ʱ�ȭ
			count_horizontal_max(i, j); //�迭 ���� ��ȯ ���Ͽ��� �� ���� �ִ� ���� Ȯ��
			count_vertical_max(i,j); //�迭 ���� ��ȯ ���Ͽ��� �� ���� �ִ� ���� Ȯ��
		}
	}
	//���
	cout<<answer;
}
