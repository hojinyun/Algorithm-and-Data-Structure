#include <iostream>
#include <queue>

using namespace std;

//가로 세로 길이 및 마지막으로 익은 토마토 위치 및 안익은 토마토 개수 
int m=0, n=0, row=0, col=0, num_not_riped=0;
//토마토 위치 저장 및 각 토마토마다 익은 날짜를 알기 위한 배열 
int box[1000][1000]={0}, days[1000][1000]={0}; 
queue<pair<int,int>> q; //bfs를 위한 큐
//이동 가능한 4방향
int dx[4] = {0,0,1,-1};
int dy[4]={1,-1,0,0};

int main(){
	//입력 
	cin >> m >> n; 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> box[i][j];
			if(box[i][j] == 0) num_not_riped++; //안익은 토마토 개수 
			if(box[i][j] == 1) q.push({i,j}); //시작 
		}
	}
	while(!q.empty()){
		pair<int, int> tmp = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			if(num_not_riped==0) break;
			row = tmp.first+dx[i];
			col = tmp.second + dy[i];
			//박스 범위 밖이거나 이미 익은 경우 넘어감 
			if(row<0 || row>=n || col<0 || col>=m || box[row][col]==1 || box[row][col]==-1) continue;
			
			q.push({row,col}); //큐에 안익은 위치 저장 
			box[row][col] = 1; //익은 상태로 변환 
			num_not_riped--; //안익은 토마토 개수 줄임 
			days[row][col]=days[tmp.first][tmp.second]+1; //읶는데 걸리는 일 수		
		}
	}
	//출력 
	if(num_not_riped>0) cout<<-1;
	else cout<< days[row][col];
}
