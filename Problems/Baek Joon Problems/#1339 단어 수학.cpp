//https://excited-hyun.tistory.com/145
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, answer=0, word_len[10]={0}, alphabet[26]={0};
char word[10][8]={0};

int main(){
	//입력
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> word[i];
		word_len[i] = strlen(word[i]); //몇번째 자리수인지 알기 위해 글자 길이 저장
	}
	//각 알파벳마다 몇번째 자리수에 값이 있는지 저장
	for(int i = 0; i < n; i++){
		int multiple_ten = 1;
		for(int j = word_len[i]-1; j >=0; j--){
			alphabet[word[i][j]-'A'] += multiple_ten;
			multiple_ten *= 10;
		}
	}
	//제일 큰 값을 가진 알파벳 순으로 재정렬
	sort(alphabet, alphabet+26, greater<int>());
	//제일 큰 값부터 9를 차례대로 곱해주면서 답에 더함
	for(int i = 0; i < 10; i++) answer+=alphabet[i]*(9-i);
	//출력
	cout << answer;
}