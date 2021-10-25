#include <iostream>

using namespace std;

string text[50];
char pattern[50];

string patternFinder(int number){
	int textSize = text[0].size();
	for(int i = 0; i < textSize; i++){
		int c = text[0][i];
		for(int j = 0; j < number; j++){
			if(c != text[j][i]){
				pattern[i] = '?';
				break;
			}
			else{
				pattern[i] = c;
			}
		}
	}
	return pattern;
}

int main(void){
	int number;
	cin >> number;
	for(int i = 0; i < number; i++){
		cin>> text[i];
	}
	patternFinder(number);
}
