#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	string word, answer[1000];
	//입력 
	getline(cin, word);
	//i는 지우려는 접두사 순서 
	for(int i = 0; i < word.size(); i++){
		//i부터 시작함으로써 앞에 접두사를 날릴 수 있음 
		for(int j = i; j < word.size(); j++){
			//정답에 문자 한개 저장 
			answer[i] += word[j];
		}
	}
	//알파벳 순으로 정렬 #include <algorithm> 필요함 
	sort(answer, answer+word.size());
	//출력
	for(int i = 0; i < word.size(); i++){
		cout<<answer[i]<<endl;
	}
}
