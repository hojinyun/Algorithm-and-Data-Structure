#include <iostream>
#include <stack>

using namespace std;

int main(){
	int cnt = 0, temp = 0, multiple = 1;
	stack<int> answer;
	string s;
	//�Է�
	getline(cin, s);
	//ù��° �ڸ������� �����ؾ� �ǹǷ� s�� �ִ� ũ����� ����
	for(int i = s.size()-1; i >= 0; i--){
		//ù��° ��츦 ������ �� 3��° ���긶�� ���ÿ� �ְ� ���� �ʱ�ȭ 
		if(cnt%3 == 0 && i != s.size()-1){
			answer.push(temp);
			temp = 0; 
			multiple = 1;
		} 
		//s[i]�� int������ �ٲ� 2�� n�� �����Ͽ� temp�� �� �� 
		temp += (s[i]-'0')*multiple;
		//2�� 1�� �߰�
		multiple *= 2;
		cnt++;
	}
	//���� ������ ���� �� �߰� 
	answer.push(temp);
	//��� 
	while(!answer.empty()){
		cout<<answer.top();
		answer.pop();
	}
	
}
