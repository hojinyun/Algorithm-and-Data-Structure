#include <iostream>

using namespace std;

int main(){
	string s;
	int alphabet[26];
	//�迭 �� -1�� �ʱ�ȭ 
	fill_n(alphabet, 26, -1);
	//�Է� 
	getline(cin, s); 
	//���ĺ��� �´� �ε��� ����
	for(int i = 0; i < s.size(); i++){
		//���࿡ �̹� ���� �����ϸ� �ѱ� 
		if(alphabet[s[i]-'a'] == -1) alphabet[s[i]-'a'] = i;
	}
	//��� 
	for(int i = 0; i < 26; i++){
		cout << alphabet[i] << " ";
	}
}
