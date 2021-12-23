#include <iostream>
#include <queue>

using namespace std;

const int EMPTY = 0, WALL = 1, DISEASE =2; 
int n, m, answer = 0, num_walls = 3;
int map[8][8], test[8][8], simulation[8][8];

bool spread_check(int row, int col){
	//Check if inbound or empty space
	if(row<0 || row>=n || col<0 || col>=m || simulation[row][col] != EMPTY) return false;
	return true;
}

//BFS
void disease_simulation(void){
	//Clone test array
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			simulation[i][j] = test[i][j];
		}
	}
	
	//Find diseases coordinates
	queue<pair<int, int> > q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(simulation[i][j] == DISEASE){
				q.push({i,j});
			}
		}
	}
	//Spread disease
	while(!q.empty()){
		
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		 
		if(spread_check(row+1,col)){
			simulation[row+1][col] = DISEASE;
			q.push({row+1, col});
		}
		if(spread_check(row-1,col)){
			simulation[row-1][col] = DISEASE;
			q.push({row-1, col});
		}
		if(spread_check(row,col+1)){
			simulation[row][col+1] = DISEASE;
			q.push({row, col+1});			
		}
		if(spread_check(row,col-1)){
			simulation[row][col-1] = DISEASE;
			q.push({row, col-1});			
		}
	}
	
	int zeros = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(simulation[i][j] == EMPTY){
				zeros++;
			}
		}
	}
	answer = max(answer, zeros);
}

//Backtracking
void create_walls(int walls_left){
	if(walls_left == 0){
		disease_simulation();
		return;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(test[i][j] == EMPTY){
				test[i][j] = WALL;
				create_walls(walls_left-1);
				test[i][j] = EMPTY;
			}
		}
	}
}

int main(void){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j] == EMPTY){
				for(int k = 0; k < n; k++){
					for(int l = 0; l < m; l++){
						test[k][l] = map[k][l];
					}
				}
				//시간 초과 방지 
				test[i][j] = WALL;
				create_walls(num_walls-1);
				test[i][j] = EMPTY;
			}
		}
	}
	
	cout<<answer<<endl;
}
