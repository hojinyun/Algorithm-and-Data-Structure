#include <iostream>

using namespace std;

int main(){
	string s;
	int alphabet[26] = {};
	//�Է� 
	getline(cin, s); 
	//���ĺ��� �´� �ε����� ���� +1 
	for(int i = 0; i < s.size(); i++){
		alphabet[s[i]-'a']++;
	}
	//��� 
	for(int i = 0; i < 26; i++){
		cout << alphabet[i] << " ";
	}
}
