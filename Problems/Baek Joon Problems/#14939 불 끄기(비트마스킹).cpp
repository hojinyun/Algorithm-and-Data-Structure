#include <iostream>

using namespace std;

bool original[10][10], test[10][10];
int answer = 1e9;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void toggle(int x, int y){
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		//if not out of range
		if(!(nx < 0 || nx >= 10 || ny < 0 || ny >= 10)) test[nx][ny] = !test[nx][ny];
	}
	test[x][y] = !test[x][y];
}

bool alloff(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if(test[i][j]) return false;
		}
	}
	return true;
}

void init_array(){
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			test[i][j] = original[i][j];
		}
	}
}


void brute_force(){
	//Goes up till 2^10 which is all possible combination for the first line
	for(int step = 0; step < (1 << 10); step++){
		//step = combination of first line
		int counter = 0;
		init_array();
		//check if the light is on for the "step" 
		for(int bit = 0; bit < 10; bit++){
			if(step & (1 << bit)){
				counter++;
				toggle(0, bit);
			}
		}
		for(int x = 1; x < 10; x++){
			for(int y = 0; y < 10; y++){
				if(test[x-1][y]){
					toggle(x,y);
					counter++;
				}
			}
		}
		if(alloff()) answer = min(counter, answer);
	}
}

int main(void){
	
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			char c;
			cin >> c;
			if(c=='O'){
				original[i][j] = 1;
			}
		}
	}
	
	brute_force();
	
	if(answer == 1e9) cout << -1;
	else cout << answer;
	
}
