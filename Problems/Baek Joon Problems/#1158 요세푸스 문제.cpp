#include <iostream>
#include <queue>

using namespace std;

int main(void){
	queue<int> q;
	queue<int> answer;
	int n, k;
	cin >> n;
	cin >> k;
	
	//ť�� 1���� n������ �� ��� �ֱ�
	for(int i = 1; i <= n; i++){
		q.push(i);
	}
	
	//�� k��°���� ��� �ƴ� ���� ť�� �ٽ� push �� pop
	cout<<"<";
	while(!q.empty()){
		for(int i = 1; i < k; i++){
			q.push(q.front());
			q.pop();
		}
	//������ �Ѱ� ������ ��� ',' ���� ���
		if(q.size()==1) cout<<q.front();
		else cout<<q.front()<<", ";
		q.pop();
	}
	cout<<">";
}
