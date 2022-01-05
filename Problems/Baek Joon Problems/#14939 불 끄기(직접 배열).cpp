#include <iostream>

using namespace std;

bool original[10][10];
int answer = 1e9;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void toggle(int x, int y, bool test_array[10][10]){
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		//if not out of range
		if(!(nx < 0 || nx >= 10 || ny < 0 || ny >= 10)) test_array[nx][ny] = !test_array[nx][ny];
	}
	test_array[x][y] = !test_array[x][y];
}

bool alloff(bool array[10][10]){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if(array[i][j]) return false;
		}
	}
	return true;
}

void copy(bool array1[10][10], bool array2[10][10], bool array[10][10]){
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			array1[i][j] = array[i][j];
			array2[i][j] = array[i][j];
		}
	}
}


void brute_force(int x, int sum, bool array[10][10]){
	//after checking all possible combination for first line
	if(x == 10){
		bool test_array3[10][10] = {0, };
		for(int i = 0; i<10; i++){
			for(int j = 0; j<10; j++){
				test_array3[i][j] = array[i][j];
			}
		}
		//toggle for all lines after first line 
		for(int i = 1; i < 10; i++){
			for(int j = 0; j < 10; j++){
				if(test_array3[i-1][j]){
					toggle(i,j, test_array3);
					sum++;
				}
			}
		}
		if(alloff(test_array3)) answer = min(answer, sum);
		return;
	}
	
	//Backtracking
	bool test_array1[10][10], test_array2[10][10] = {0, };
	copy(test_array1, test_array2, array);
	
	//when not pressing
	brute_force(x+1, sum, test_array1);
	
	//when pressing
	toggle(0, x, test_array2);
	brute_force(x+1, sum+1, test_array2);
	
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
	
	brute_force(0, 0, original);
	
	if(answer == 1e9) cout << -1;
	else cout << answer;
	
}
