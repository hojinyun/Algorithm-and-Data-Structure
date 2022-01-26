#include <iostream>

using namespace std;

int main(){
	string s;
	//입력 
	getline(cin, s);
	for(int i = 0; i < s.size(); i++){
		//소문자인 경우 
		if(s[i]>='a' && s[i]<='z'){
			//13을 더 했을 때 z를 넘어가면 다시 a부터 셀 수 있도록 함
			if(s[i]+13 > 'z') s[i]-=13;
			else s[i]+=13;
		}
		//대문자인 경우 
		else if(s[i]>='A' && s[i]<='Z'){
			//13을 더 했을 때 Z를 넘어가면 다시 A부터 셀 수 있도록 함
			if(s[i]+13 > 'Z') s[i]-=13;
			else s[i]+=13;
		}
	}
	//출력 
	for(int i = 0; i < s.size(); i++){
		cout << s[i];
	}
}
