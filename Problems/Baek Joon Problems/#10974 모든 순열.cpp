#include <iostream>

using namespace std;


bool visited[8]={}; //��� ���� ���� Ȯ�� 
int n, answer[8]={}; //�Է°� �� ���� ���� �迭 

void brute_force(int index){
	//���� �� ä��� ���� �� �� ��� 
	if(index==n){
		for(int i = 0; i<n; i++) cout<<answer[i]<<" ";
		cout<<"\n";
		return;
	}
	//��Ʈ��ŷ 
	for(int i = 1; i <= n; i++){
		if(visited[i]) continue; //�̹� ������� ���̸� �ѱ�� 
		visited[i]=true; //��� ���� ������ ��ȯ 
		answer[index]=i; //���� �迭�� �� ���� 
		brute_force(index+1); //���� �ε����� �Ѿ�� 
		answer[index]=0; //�����൵ ������ Ȥ�� �𸣴� 0���� �ٽ� �ʱ�ȭ 
		visited[i]=false; //��� ������ ���� ������ ��ȯ 
	}
}

int main(){
	//�Է� 
	cin >> n;
	//���Ʈ���� �˰��� ���� 
	brute_force(0);
}
