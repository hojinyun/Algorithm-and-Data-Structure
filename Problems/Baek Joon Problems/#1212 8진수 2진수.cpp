#include <iostream>

using namespace std;

int main(){
	string s, binary[8]={"000","001","010","011","100","101","110","111"};
	//�Է�
	getline(cin, s);
	//�� �ڸ��� ���ڸ��� �˸´� ������ �� ���
	for(int i = 0; i < s.size(); i++){
		//���� ù��° ������ ��� �տ� 0�����ϰ� ����ϵ���
		if(i == 0){
			if(s[i] == '0') cout << "0"; //0�� �ִ� ����̹Ƿ� 0�� ���
			else if(s[i] == '1') cout << "1";
			else if(s[i] == '2') cout << "10";
			else if(s[i] == '3') cout << "11";
			else cout<<binary[s[i]-'0'];
		}
		else cout<<binary[s[i]-'0'];
	}
}

/*
#include <iostream>
#include <stack>

using namespace std;

int main(){
	int temp[3] = {0,0,0};
	string s;
	stack<int> answer;
	getline(cin, s);
	//0�� ��� ���� ó��
	if(s[0] == '0'){
		cout<< 0;
		return 0;
	}
	for(int i = s.size()-1; i >= 0; i--){
		//2�� �¼��� �°� �� ���� 
		if((s[i]-'0')/4){
			temp[0] = 1;
			if((s[i]-'0'-4)/2){
				temp[1] = 1;
				if((s[i]-'0'-4-2)/1) temp[2] = 1;
			}
			else if((s[i]-'0'-4)/1) temp[2] = 1;
		}
		else if((s[i]-'0')/2){
			temp[1] = 1;
			if((s[i]-'0'-2)/1) temp[2] = 1;
		}
		else if((s[i]-'0')/1) temp [2] = 1;
		//temp�� ����� ������ �� ���ÿ� ���� 
		for(int j = 2; j >= 0; j--){
			if(i==0 && temp[j]==0){
				if(temp[j-1]==1||temp[j-2]==1) answer.push(temp[j]);
				else continue;
			}
			else answer.push(temp[j]);
		}
		//���� �ʱ�ȭ 
		for(int k = 0; k < 3; k++) temp[k] = 0;
	}
  	//���� ���
	while(!answer.empty()){
		cout<<answer.top();
		answer.pop();
	}
} */
