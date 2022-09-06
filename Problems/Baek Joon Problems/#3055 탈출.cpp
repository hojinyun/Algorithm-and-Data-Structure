#include <iostream>
#include <queue>

using namespace std;

//bool visited[50][50]={0};
char map[50][50]={0};
int r=0, c=0, count[50][50]={0};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
queue<pair<int,int>> q, water;

int main(){
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> map[i][j];
			if(map[i][j]=='S') q.push({i,j});
			if(map[i][j]=='*') water.push({i,j});
		}
	}
	//BFS
	while(!q.empty()){
		/*cout<<"---------WATER----------"<<endl;
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					cout<<map[i][j];
				}
				cout<<endl;
		}
		cout<<"----------GOSM---------"<<endl;
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++){
					cout<<count[i][j];
				}
				cout<<endl;
		}*/
		int cnt=q.size(), water_cnt=water.size();
		while(water_cnt--){
			int water_row=water.front().first, water_col=water.front().second;
			water.pop();
			for(int i = 0; i < 4; i++){
				int next_water_row=water_row+dy[i], next_water_col=water_col+dx[i];
				if(next_water_row<0||next_water_col<0||next_water_row>=r||next_water_col>=c||map[next_water_row][next_water_col]=='X'||map[next_water_row][next_water_col]=='*'||map[next_water_row][next_water_col]=='D') continue;
				map[next_water_row][next_water_col]='*';
				water.push({next_water_row,next_water_col});
			}
		}
		while(cnt--){
			int row=q.front().first, col=q.front().second;
			q.pop();
			for(int i = 0; i < 4; i++){
				int next_row=row+dy[i], next_col=col+dx[i];
				if(next_row<0||next_col<0||next_row>=r||next_col>=c||count[next_row][next_col]||map[next_row][next_col]=='*'||map[next_row][next_col]=='X') continue;
				if(map[next_row][next_col]=='D'){
					cout<<count[row][col]+1;
					return 0;
				}
				
				if(map[next_row][next_col]=='.'){
					q.push({next_row,next_col});
					count[next_row][next_col]=count[row][col]+1;
				}
			}
		}
		

	}
	cout<<"KAKTUS";
}