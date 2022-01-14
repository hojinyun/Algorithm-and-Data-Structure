#include <iostream>
#include <stack>

using namespace std;

int n, empty_space[500];
string str;
stack<char> s;

int main(void){
	cin >> n;
	for(int i = 0; i < n; i++){
		getline(cin, str);
		for(int j = 0; j < str.size(); j++){
			if(str[j] == ' '){
				empty_space[counter]=j;
				counter++;
			}
		}
		for(int k = 0; k < counter+1; k++){
			
				
		}
		answer[i] = str;
	}
	for(int i = 1; i < n+1; i++){
		cout << answer[i] <<endl;
	}
}
