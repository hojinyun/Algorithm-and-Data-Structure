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
		if(counter == 0){
			for(int start = 0; start < str.size()/2; start++){
				//cout<<"swap: " <<str[start]<<" and "<<str[str.size()-start]<<endl;
				char temp;
				temp = str[start];
				str[start] = str[str.size()-1-start];
				str[str.size()-1-start] = temp;
			}
			cout << str << endl;
		}
		else{
			for(int k = 0; k < counter+1; k++){
				if(k == 0){
					//cout<<"start"<<endl;
					for(int start = 0; start < empty_space[k]/2; start++){
						char temp;
						//cout<<"swap: " <<str[start]<<" and "<<str[empty_space[k]-start-1]<<endl;
						temp = str[start];
						//cout<<"4th "<<str[4]<<endl;
						//cout<<"temp: "<<temp<<endl;
						str[start] = str[empty_space[k]-start-1];
						//cout<<"number: "<<empty_space[k]-start-1<<endl;
						str[empty_space[k]-start-1] = temp;
						//cout<<"check "<<str[empty_space[k]-start-1]<<endl;
					}
				}
				else if(k == counter){
					//cout<<"end"<<endl;
					for(int start = empty_space[k-1]+1; start < (empty_space[k-1]+str.size())/2+1; start++){
						char temp;
						temp = str[start];
						str[start] = str[empty_space[k-1]+str.size()-start];
						str[empty_space[k-1]+str.size()-start] = temp;
					}
				}
				else{
					//cout<<"middle"<<endl;
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

