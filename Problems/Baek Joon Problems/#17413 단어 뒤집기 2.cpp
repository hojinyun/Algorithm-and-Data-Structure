#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    string original = "";
    bool tag = false;
    getline(cin, original);
    //마지막 단어도 뒤집어주기 위해 마지막 줄에 공백 추가 
    original += ' ';
    stack<char> str; 
    for (int i = 0; i < original.size(); i++) {
		//태그 아니니까 뒤집기 
		if(!tag){
			//공백 보이면 단어 순서 거꾸로 출력
	        if (original[i] == ' '|| original[i] == '<') {
	        	if(original[i] == '<') tag = true; //tag 안에 들어온걸 명시 
	        	
	            while (!str.empty()) {
	                cout << str.top();
	                str.pop();
	            }
	            cout << original[i]; //공백 출력 
	        }
			//공백 아니면 스택에 집어 넣기 
	        else str.push(original[i]);
		}
		//괄호 안 이니까 그대로 출력 
		else{
			if(original[i] == '>') tag = false;
			cout << original[i];
		}
    }
}
