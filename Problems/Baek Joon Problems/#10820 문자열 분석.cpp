#include <iostream>

using namespace std;

int main(){
	string s;
	//�迭 �� 0���� �ʱ�ȭ 
	int answer[4] = {};
	//�Է��� �� ������ ���α׷� ���� 
	while(getline(cin,s)){
		for(int i = 0; i < s.size(); i++){
			//�ҹ����� �� 
			if(s[i] >= 'a' && s[i] <= 'z') answer[0]++;
			//�빮���� �� 
			else if(s[i] >= 'A' && s[i] <= 'Z') answer[1]++;
			//������ �� 
			else if(s[i] >= '0' && s[i] <= '9') answer[2]++;
			//������ �� 
			else if(s[i] == ' ') answer[3]++;
			else continue;
		}
		//��� 
		for(int i = 0; i < 4; i++){
			cout << answer[i] << " ";
			answer[i] = 0; //��� �� 0���� �ʱ�ȭ 
		}
	}
}
