#include <iostream>

using namespace std;

int n=0, count=0, board[14]={0};

//���� ���� �� �ִ��� Ȯ�� 
bool check(int col){
	//Ȯ���ϰ� ���� �� ������ ��� �� Ȯ�� 
	for(int i=0; i<col; i++){
		//���� ���� �� ���� �ְų� �밢���� ���(���� ���̿� ���� ���̰� ���� ���) 
		if(board[col]==board[i] || col-i==abs(board[col]-board[i])) return false;
	}
	//��� ����Ͽ����� true ��ȯ 
	return true;
}

void brute_force(int col){
	//������ �� Ȯ���Ͽ����� ���� 1�� �߰� 
	if(col==n){
		count++;
		return;
	}
	//���� ��� ���� ���� �־�� 
	for(int row=0; row<n; row++){
		board[col]=row; //���� �� ���� 
		//���� �� �Է� �����ϸ� ���� ���� �Ѿ�� 
		if(check(col)) brute_force(col+1);
	}
}

int main(){
	//�Է� 
	cin >> n;
	//��� �ڸ��� ���� �־�� ����� �� 
	brute_force(0);
	//��� 
	cout << count;
}
