#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

bool visited[8][8]={0};
string map[8];
int dx[9]={-1,-1,-1,1,1,1,0,0,0};
int dy[9]={0,-1,1,0,-1,1,0,-1,1};
vector<pair<int,int>> wall;
queue<pair<int,int>> q;


int main(){
	for(int i = 0; i < 8; i++){
		cin >> map[i];
		for(int j = 0; j < 8; j++){
			if(map[i][j]=='#') wall.push_back({i,j});
		}
	}
	//캐릭터 이동
	q.push({7,0});
	while(!q.empty()){
		int cnt = q.size();
		memset(visited,0,sizeof(visited));
		while(cnt--){
			int row = q.front().first, col = q.front().second;
			q.pop();
			
			if(row==0 && col==7){
				cout<<1;
				return 0;
			}
			//벽이 캐릭터 있는 칸으로 온 경우 
			if(map[row][col]=='#') continue; 
			
			for(int i = 0; i < 9; i++){
				int next_row=row+dy[i], next_col=col+dx[i];
				if(next_row<0||next_col<0||next_row>=8||next_col>=8||map[next_row][next_col]=='#') continue;
				visited[next_row][next_col] = true;
				q.push({next_row,next_col});
			}
		}
		
		//벽 이동
		for(int i = 0; i < 8; i++) map[i] = "........";
		for(int i = 0; i < wall.size(); i++){
			if(wall[i].first==7){
				wall.erase(wall.begin()+i);
				i--;
				continue;
			}
			map[wall[i].first+1][wall[i].second]='#';
			wall[i].first++;
		}
	}
	cout<<0;
}
