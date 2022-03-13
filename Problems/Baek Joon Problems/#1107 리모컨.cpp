#include <iostream>
#define MIN(a,b) (a<b ? a : b)

using namespace std;

int n, m, answer = 500001, counter = 0;
bool broken[10]={};

//��� ��ư�� ������ ����� ���� Ȯ���ϴ� ����Լ�
void brute_force(string n_string){
	//0���� 9���� ��� ��ư Ȯ��
	for(int i=0; i<10; i++){
		//���峭 ��ư �����ϰ� ����
		if(!broken[i]){
			//������ ��ư ���� ����
			string temp_n = n_string + to_string(i);
			//ä�ΰ� ���� ���յ� ���ڿ��� �Ÿ�+���� ��ư �� 
			answer = MIN(answer, abs(n-stoi(temp_n))+temp_n.length());
			//���� 6�ڸ� ��ä���ٸ� 6�ڸ� ä�� ������ �� �غ���
			if(temp_n.length() < 6) brute_force(temp_n);
		} 
	}
}

int main(){
	//�Է�
	cin >> n;
	cin >> m;
	for(int i = 0; i < m; i++){
		int temp;
		cin >> temp;
		broken[temp] = true;
	}
	//100�������� +,-�� ������ ���
	answer = min(answer, abs(n-100));
	//��� ��ư�� �ȵǴ� ��츦 �����ϰ� ��� ��ư�� ����� ����
	//���� �Ÿ� ��� �Լ� ����
	if(m!=10){
		brute_force("");
	}
	cout<<answer;
}
