#include <iostream>

using namespace std;

int main(){
	string s;
	//�Է� 
	getline(cin, s);
	for(int i = 0; i < s.size(); i++){
		//�ҹ����� ��� 
		if(s[i]>='a' && s[i]<='z'){
			//13�� �� ���� �� z�� �Ѿ�� �ٽ� a���� �� �� �ֵ��� ��
			if(s[i]+13 > 'z') s[i]-=13;
			else s[i]+=13;
		}
		//�빮���� ��� 
		else if(s[i]>='A' && s[i]<='Z'){
			//13�� �� ���� �� Z�� �Ѿ�� �ٽ� A���� �� �� �ֵ��� ��
			if(s[i]+13 > 'Z') s[i]-=13;
			else s[i]+=13;
		}
	}
	//��� 
	for(int i = 0; i < s.size(); i++){
		cout << s[i];
	}
}
