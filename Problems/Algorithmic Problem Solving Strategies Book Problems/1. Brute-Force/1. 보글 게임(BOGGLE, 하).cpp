#include <iostream>

using namespace std;

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1,1};
string dictionary[4] = {"GEEKS", "FOR", "QUIZ", "GO"};
char board[3][3] = {{'G', 'I', 'Z'},
					{'U', 'E', 'K'},
                    {'Q', 'S', 'E'}};
bool inRange(int y, int x){
	if(y >= 0 && y <= 2 && x >= 0 && x <= 2 ) return true;
	return false;
}

bool hasWord(int y, int x, const string& word){
	if(!inRange(y,x)) return false; //out of range
	
	if(board[y][x] != word[0]) return false; //first word wrong
	if(word.size() == 1) return true; //one word and matches
	for(int direction = 0; direction < 8; direction++){
		int nextY = y+dy[direction], nextX = x+dx[direction];
		if(hasWord(nextY, nextX, word.substr(1))){
			return true;
		}
	}
	return false;
}

int main(void){
    cout<< hasWord(0, 0, dictionary[0]) << endl;
}
