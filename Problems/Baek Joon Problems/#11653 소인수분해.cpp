#include <iostream>

using namespace std;

int main(){
	int n;
	//�Է� 
	cin >> n;
	bool isPrime[n];
	//�����佺�׳׽��� ü ����
	for(int i=2; i<=n; i++) isPrime[i]=true; //true�� �迭 �ʱ�ȭ
	for(int i=2; i<=n; i++){
		if(isPrime[i]==false) continue; //�̹� false�� �� ����
		for(int j=i+i; j<=n; j+=i) isPrime[j] = false; //����� ��� false�� ���� 
	}
	//���μ�����
	while(n!=1){
		//2���� n���� �������� �� Ȯ�� 
		for(int i=2; i<=n; i++){ //int i = temp; i���� ���� �ؼ� �����ϴ� ����� ����
			//n�� ������ �������� �Ҽ��� i�� ��� 
			if(n%i==0 && isPrime[i]){
				//��� 
				cout<<i<<endl;
				//���� ���� ���ϱ� ���� n�� i��ŭ �������ش� 
				n /= i;
				//�ٽ� 2���� Ȯ���ϱ� ���� for�� Ż�� 
				break;
			}
		}
	}
}
