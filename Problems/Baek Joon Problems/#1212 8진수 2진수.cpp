#include <iostream>

using namespace std;

int main(){
	string s, binary[8]={"000","001","010","011","100","101","110","111"};
	//입력
	getline(cin, s);
	//각 자리의 숫자마다 알맞는 이진수 값 출력
	for(int i = 0; i < s.size(); i++){
		//제일 첫번째 숫자인 경우 앞에 0무시하고 출력하도록
		if(i == 0){
			if(s[i] == '0') cout << "0"; //0만 있는 경우이므로 0만 출력
			else if(s[i] == '1') cout << "1";
			else if(s[i] == '2') cout << "10";
			else if(s[i] == '3') cout << "11";
			else cout<<binary[s[i]-'0'];
		}
		else cout<<binary[s[i]-'0'];
	}
}

/*
#include <iostream>
#include <stack>

using namespace std;

int main(){
	int temp[3] = {0,0,0};
	string s;
	stack<int> answer;
	getline(cin, s);
	//0인 경우 예외 처리
	if(s[0] == '0'){
		cout<< 0;
		return 0;
	}
	for(int i = s.size()-1; i >= 0; i--){
		//2의 승수에 맞게 값 저장 
		if((s[i]-'0')/4){
			temp[0] = 1;
			if((s[i]-'0'-4)/2){
				temp[1] = 1;
				if((s[i]-'0'-4-2)/1) temp[2] = 1;
			}
			else if((s[i]-'0'-4)/1) temp[2] = 1;
		}
		else if((s[i]-'0')/2){
			temp[1] = 1;
			if((s[i]-'0'-2)/1) temp[2] = 1;
		}
		else if((s[i]-'0')/1) temp [2] = 1;
		//temp에 저장된 이진수 값 스택에 저장 
		for(int j = 2; j >= 0; j--){
			if(i==0 && temp[j]==0){
				if(temp[j-1]==1||temp[j-2]==1) answer.push(temp[j]);
				else continue;
			}
			else answer.push(temp[j]);
		}
		//변수 초기화 
		for(int k = 0; k < 3; k++) temp[k] = 0;
	}
  	//정답 출력
	while(!answer.empty()){
		cout<<answer.top();
		answer.pop();
	}
} */
