/*
#include <iostream>

using namespace std;

int n, empty_space[501];

int main(void){
	cin >> n;
	cin.ignore();
	for(int i = 0; i < n; i++){
		string str = "";
		getline(cin, str);
		int counter = 0;
		for(int j = 0; j < str.size(); j++){
			if(str[j] == ' '){
				empty_space[counter]=j;
				counter++;
			}
		}
		//�ܾ �ϳ� �ۿ� ���� ��
		if(counter == 0){
			for(int start = 0; start < str.size()/2; start++){
				char temp;
				temp = str[start];
				str[start] = str[str.size()-1-start];
				str[str.size()-1-start] = temp;
			}
			cout << str << endl;
		}
		//�ܾ ������ ���� ��
		else{
			for(int k = 0; k < counter+1; k++){
				//ù��° ����
				if(k == 0){
					for(int start = 0; start < empty_space[k]/2; start++){
						char temp;
						temp = str[start];
						str[start] = str[empty_space[k]-start-1];
						str[empty_space[k]-start-1] = temp;
					}
				}
				//������ ����
				else if(k == counter){
					for(int start = empty_space[k-1]+1; start < (empty_space[k-1]+str.size())/2+1; start++){
						char temp;
						temp = str[start];
						str[start] = str[empty_space[k-1]+str.size()-start];
						str[empty_space[k-1]+str.size()-start] = temp;
					}
				}
				//�߰� �����
				else{
					for(int start = empty_space[k-1]+1; start < (empty_space[k]+(empty_space[k-1]+1))/2; start++){
						char temp;
						temp = str[start];
						str[start] = str[empty_space[k]+empty_space[k-1]-start];
						str[empty_space[k]+empty_space[k-1]-start] = temp;
					}
				}
			}
			cout << str <<endl;
		}
	}
}
*/

//Solution using stack
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    cin.ignore();
	for(int i = 0; i < n; i++){
        string original = "";
        getline(cin, original);
        //������ �ܾ �������ֱ� ���� ������ �ٿ� ���� �߰� 
        original += ' ';
        stack<char> str; 
        for (int i = 0; i < original.size(); i++) {
        	//���� ���̸� �ܾ� ���� �Ųٷ� ��� 
            if (original[i] == ' ') {
                while (!str.empty()) {
                    cout << str.top();
                    str.pop();
                }
                cout << original[i];
            }
			//���� �ƴϸ� ���ÿ� ���� �ֱ� 
            else str.push(original[i]);
        }
    }
}

