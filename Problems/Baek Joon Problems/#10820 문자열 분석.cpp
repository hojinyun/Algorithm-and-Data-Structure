#include <iostream>

using namespace std;

int main(){
	string s;
	//배열 값 0으로 초기화 
	int answer[4] = {};
	//입력을 못 받으면 프로그램 종료 
	while(getline(cin,s)){
		for(int i = 0; i < s.size(); i++){
			//소문자일 때 
			if(s[i] >= 'a' && s[i] <= 'z') answer[0]++;
			//대문자일 때 
			else if(s[i] >= 'A' && s[i] <= 'Z') answer[1]++;
			//숫자일 때 
			else if(s[i] >= '0' && s[i] <= '9') answer[2]++;
			//공백일 때 
			else if(s[i] == ' ') answer[3]++;
			else continue;
		}
		//출력 
		for(int i = 0; i < 4; i++){
			cout << answer[i] << " ";
			answer[i] = 0; //출력 후 0으로 초기화 
		}
	}
}
