//https://kibbomi.tistory.com/210
#include <iostream>
#include <queue>
#include <set>

using namespace std;

bool visited[1000][1000]={0};
char map[1000][1000]={0};
int n=0, m=0, group_count=-1, answer[1000][1000]={0}, area[1000000]={0}, group[1000][1000]={0};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};


int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>> map[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j]=='0'&&!visited[i][j]){
				group_count++;
				queue<pair<int,int>> q;
				q.push({i,j});
				visited[i][j]=true;
				int zeros_count = 1;
				while(!q.empty()){
					int row = q.front().first, col = q.front().second;
					q.pop();
					group[row][col]=group_count;
					
					for(int i = 0; i < 4; i++){
						int next_row=row+dx[i], next_col=col+dy[i];
						if(next_row<0||next_col<0||next_row>=n||next_col>=m||visited[next_row][next_col]) continue;
						if(map[next_row][next_col]=='1') continue;
						//0인 경우 
						q.push({next_row,next_col});
						visited[next_row][next_col]=true;
						zeros_count++;
					}
				}
				area[group_count]=zeros_count;
			}
			
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m;j++){
			if(map[i][j]=='1'){
				int sum = 1;
				set<int> s;
				for(int k = 0; k < 4; k++){
					int next_row=i+dx[k], next_col=j+dy[k];
					if(next_row<0||next_col<0||next_row>=n||next_col>=m||map[next_row][next_col]=='1') continue;
					//다음 row col이 0인 상태에서 확인하지 않은 0의 그룹이 있는 경우 
					if(s.find(group[next_row][next_col])==s.end()){
						sum+=area[group[next_row][next_col]];
						s.insert(group[next_row][next_col]);  
					}
				}
				answer[i][j]=sum;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j]=='1') cout<<answer[i][j]%10;
			else cout<<0;
		}
		cout<<'\n';
	}
	
}
