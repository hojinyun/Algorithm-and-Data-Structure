#include <iostream>
#include <queue>

using namespace std;

bool visited[1000][1000][10]={0};
int n=0, m=0, k=0, map[1000][1000]={0};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};


int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char temp;
			cin>> temp;
			map[i][j]=temp-'0';
		}
	}
	
	queue<pair<pair<int,int>,pair<int, int>>> q;
	q.push({{0,0},{1,0}});
	visited[0][0][0] = true;
	while(!q.empty()){
		int row = q.front().first.first;
		int col = q.front().first.second;
		int cnt = q.front().second.first;
		int wall = q.front().second.second;
		q.pop();
		
		if(row==n-1 && col==m-1){
			cout<<cnt;
			return 0;
		}
		for(int i = 0; i < 4; i++){
			int next_row=row+dy[i], next_col=col+dx[i];
			if(next_row<0||next_col<0||next_row>=n||next_col>=m||visited[next_row][next_col][wall]) continue;
			if(map[next_row][next_col]==0){
				visited[next_row][next_col][wall]=true;
				q.push({{next_row,next_col},{cnt+1,wall}});
			}
			else if(map[next_row][next_col]==1 && wall<k){
				visited[next_row][next_col][wall+1]=true;
				q.push({{next_row,next_col},{cnt+1,wall+1}});
			}
		}
	}
	cout<<-1;
}
