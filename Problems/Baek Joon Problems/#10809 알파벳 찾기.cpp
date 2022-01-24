#include <iostream>

using namespace std;

int main(){
	string s;
	int alphabet[26];
	//배열 값 -1로 초기화 
	fill_n(alphabet, 26, -1);
	//입력 
	getline(cin, s); 
	//알파벳에 맞는 인덱스 저장
	for(int i = 0; i < s.size(); i++){
		//만약에 이미 값이 존재하면 넘김 
		if(alphabet[s[i]-'a'] == -1) alphabet[s[i]-'a'] = i;
	}
	//출력 
	for(int i = 0; i < 26; i++){
		cout << alphabet[i] << " ";
	}
}
