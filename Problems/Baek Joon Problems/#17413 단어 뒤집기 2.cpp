#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    string original = "";
    bool tag = false;
    getline(cin, original);
    //������ �ܾ �������ֱ� ���� ������ �ٿ� ���� �߰� 
    original += ' ';
    stack<char> str; 
    for (int i = 0; i < original.size(); i++) {
		//�±� �ƴϴϱ� ������ 
		if(!tag){
			//���� ���̸� �ܾ� ���� �Ųٷ� ���
	        if (original[i] == ' '|| original[i] == '<') {
	        	if(original[i] == '<') tag = true; //tag �ȿ� ���°� ��� 
	        	
	            while (!str.empty()) {
	                cout << str.top();
	                str.pop();
	            }
	            cout << original[i]; //���� ��� 
	        }
			//���� �ƴϸ� ���ÿ� ���� �ֱ� 
	        else str.push(original[i]);
		}
		//��ȣ �� �̴ϱ� �״�� ��� 
		else{
			if(original[i] == '>') tag = false;
			cout << original[i];
		}
    }
}
