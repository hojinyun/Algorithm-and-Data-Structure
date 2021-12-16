#include <stdio.h>
#include <ctype.h>

using namespace std;

int main(void){
	char character;
	char sentence[251];
	int counter = 0;
	int numofSentence = 0;
	char charAnswer[1000];
	int intAnswer[1000];
	while(character != '#'){
		scanf("%c", &character);
		if(character == '#'){
			break;
		}
		scanf("%[^\n]%*c", &sentence);
		for(int i = 0; i < 251; i++){
			
			if(sentence[i] == NULL){
				break;
			}
			else if(tolower(sentence[i]) == character){
				counter++;
			}
		}
		charAnswer[numofSentence] = character;
		intAnswer[numofSentence] = counter;
		numofSentence++;
		counter = 0;
		
		
	}
	for(int i = 0; i < numofSentence; i++){
		printf("%c %d\n", charAnswer[i], intAnswer[i]);
	}
	
}
