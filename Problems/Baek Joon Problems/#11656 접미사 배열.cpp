#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	string word, answer[1000];
	//�Է� 
	getline(cin, word);
	//i�� ������� ���λ� ���� 
	for(int i = 0; i < word.size(); i++){
		//i���� ���������ν� �տ� ���λ縦 ���� �� ���� 
		for(int j = i; j < word.size(); j++){
			//���信 ���� �Ѱ� ���� 
			answer[i] += word[j];
		}
	}
	//���ĺ� ������ ���� #include <algorithm> �ʿ��� 
	sort(answer, answer+word.size());
	//���
	for(int i = 0; i < word.size(); i++){
		cout<<answer[i]<<endl;
	}
}
