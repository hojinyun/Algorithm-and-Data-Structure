#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

bool visited[100][100]={0};
int n=0, answer = 200, mark_count=1, map[100][100]={0};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};


void mark_land_dfs(int row, int col){
	if(visited[row][col]) return;
	visited[row][col]=true;
	for(int i = 0; i < 4; i++){
		int new_row=row+dx[i], new_col=col+dy[i];
		if(new_row<0 || new_row>=n || new_col<0 || new_col>=n || map[new_row][new_col]==0 || visited[new_row][new_col]) continue;
		map[new_row][new_col]=mark_count;
		mark_land_dfs(new_row, new_col);
	}
}


int find_min_bfs(int x, int y){
	int current_land = map[x][y], bridge[100][100]={0};
	queue<pair<int,int>> q;
	
	q.push({x, y});
	bridge[x][y]=1;
	while(!q.empty()){
		/*cout<<"---------------"<<endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout<<bridge[i][j]<<" ";
			}
			cout<<endl;
		}*/
		int row = q.front().first, col = q.front().second;
		q.pop();
		//cout<<"Q FRONT: "<< row <<" "<< col<< endl;
		if(map[row][col] > current_land) return bridge[row][col]-2;
		for(int i = 0; i < 4; i++){
			int new_row=row+dx[i], new_col=col+dy[i];
			
			if(new_row<0 || new_row>=n || new_col<0 || new_col>=n || map[new_row][new_col]==current_land || bridge[new_row][new_col]>0) continue;
			//cout<<"PUSH: "<<new_row<<" "<<new_col<<endl;
			q.push({new_row, new_col});
			bridge[new_row][new_col]=bridge[row][col]+1;
		}
	}
	return 200;
}

int main(){
	//ют╥б 
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(map[i][j]==1&&visited[i][j]==false){
				map[i][j]=mark_count;
				mark_land_dfs(i, j);
				mark_count++;
			}
		}
	}
	
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++){
			if(map[x][y]>0){
				answer = min(answer,find_min_bfs(x,sy));
			}
		}
	}
	cout<<answer;
}
