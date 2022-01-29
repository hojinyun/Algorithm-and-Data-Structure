#include <iostream>
#define MAX 10000001

using namespace std;

bool prime[MAX] = {false, false};

int main(){
	//�ð� �ʰ� �ȵǱ� ���� �ڵ�
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = -1, answer_a = 0, answer_b = 0;
	//�����佺�׳׽��� ü
	for(int i = 2; i < MAX; i++) prime[i] = true;
	for(int i = 2; i < MAX; i++){
		if(prime[i]==false) continue;
		for(int j = i+i; j < MAX; j+=i) prime[j] = false;
	}
	//�Ҽ��� ���ϱ�
	while(n!=0){
		cin >> n;
		if(n==0) break;
		for(int i = 2; i <= n/2; i++){
			if(prime[i] && prime[n-i]){
				answer_a = i;
				answer_b = n-i;
				break;
			}
		}
		//������ ���� ��� ���
		if(answer_a == 0) cout <<"Goldbach's conjecture is wrong."<< '\n';
		//������ ���� ��� ���
		else cout << n <<" = "<< answer_a << " + " << answer_b << '\n';
		//��� �� ���� �ʱ�ȭ
		answer_a = 0;
		answer_b = 0;
	}
	
}
