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
		//단어가 하나 밖에 없을 때
		if(counter == 0){
			for(int start = 0; start < str.size()/2; start++){
				char temp;
				temp = str[start];
				str[start] = str[str.size()-1-start];
				str[str.size()-1-start] = temp;
			}
			cout << str << endl;
		}
		//단어가 여러개 있을 때
		else{
			for(int k = 0; k < counter+1; k++){
				//첫번째 공백
				if(k == 0){
					for(int start = 0; start < empty_space[k]/2; start++){
						char temp;
						temp = str[start];
						str[start] = str[empty_space[k]-start-1];
						str[empty_space[k]-start-1] = temp;
					}
				}
				//마지막 공백
				else if(k == counter){
					for(int start = empty_space[k-1]+1; start < (empty_space[k-1]+str.size())/2+1; start++){
						char temp;
						temp = str[start];
						str[start] = str[empty_space[k-1]+str.size()-start];
						str[empty_space[k-1]+str.size()-start] = temp;
					}
				}
				//중간 공백들
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
        //마지막 단어도 뒤집어주기 위해 마지막 줄에 공백 추가 
        original += ' ';
        stack<char> str; 
        for (int i = 0; i < original.size(); i++) {
        	//공백 보이면 단어 순서 거꾸로 출력 
            if (original[i] == ' ') {
                while (!str.empty()) {
                    cout << str.top();
                    str.pop();
                }
                cout << original[i];
            }
			//공백 아니면 스택에 집어 넣기 
            else str.push(original[i]);
        }
    }
}

