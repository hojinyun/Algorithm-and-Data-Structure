#include <iostream>

using namespace std;

int main(){
	string s;
	int alphabet[26] = {};
	//입력 
	getline(cin, s); 
	//알파벳에 맞는 인덱스에 개수 +1 
	for(int i = 0; i < s.size(); i++){
		alphabet[s[i]-'a']++;
	}
	//출력 
	for(int i = 0; i < 26; i++){
		cout << alphabet[i] << " ";
	}
}
