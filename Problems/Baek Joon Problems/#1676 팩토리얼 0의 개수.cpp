#include <iostream>

using namespace std;

int main(){
	int n, answer = 0;
	//�Է�
	cin >> n;
	//n���� �ϳ��� ���鼭 5�� ����� � ���� �ִ��� Ȯ�� 
	while(n){
		if(!(n%125)) answer+=3; //5^3�̹Ƿ� +3 
		else if(!(n%25)) answer+=2; //5^2�̹Ƿ� +2
		else if(!(n%5)) answer+=1; //5^1�̹Ƿ� +1
		n--;
	}
	//��� 
	cout<<answer;
}
