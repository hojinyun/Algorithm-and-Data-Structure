#include <iostream>

using namespace std;

int main(){
	//�ִ� ���� 100*1,000,000�̱� ������ long long�� ��� �� 
	long long gcd = 0; 
	int n, m;
	//�Է� 
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> m;
		//m ũ�� �迭�� ���� 
		int numbers[m];
		for(int j = 0; j < m; j++){
			cin >> numbers[j];
		}
		//��� ���� ��츦 ���� 2�� for�� 
		for(int j = 0; j < m; j++){
			for(int k = j+1; k < m; k++){
				//����� ���� ���ڰ� ���� 
				int temp, a = numbers[j], b = numbers[k];
				
				//ū ���� a�� ���� ���� if�� 
				if(a < b){
					temp = a;
					a = b;
					b = temp;
				}
				//��Ŭ���� ȣ���� 
				while(a%b){
					temp = b;
					b = a%b;
					a = temp;
				}
				gcd += b;
				
			}
		}
		//��� 
		cout << gcd <<'\n'; 
		//���� �� �ʱ�ȭ
		gcd = 0;
	}
}
