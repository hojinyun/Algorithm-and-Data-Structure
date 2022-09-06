#include <iostream>
#include <queue>
#include <cstring>

using namespace std;


int n=0,eat = 0, shark_size = 2, answer = 0;
int dx[4] = {0,-1,1,0}; //위부터 확인
int dy[4] = {-1,0,0,1}; //왼쪽부터 확인
int cnt[20][20]={0}, map[20][20]={0};
queue<pair<int,int>> q;

int main(){
	cin>> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
			if(map[i][j]==9){
				q.push({i,j});
				cnt[i][j]++;
				map[i][j]=0;
			}
		}
	}
	while(true){
		int min_dist=401, min_row=21, min_col=21;
		while(!q.empty()){
			int row = q.front().first, col = q.front().second;
			q.pop();
			/*
			cout<<"--------ROW: "<<row<<" COL: "<<col<<"----------"<<endl;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					cout<<cnt[i][j]<<" ";
				}
				cout<<endl;
			}
			*/
			for(int i = 0; i < 4; i++){
				int new_row = row+dy[i], new_col = col+dx[i];
				if(new_row<0||new_col<0||new_row>=n||new_col>=n||shark_size < map[new_row][new_col] || cnt[new_row][new_col]) continue;
				cnt[new_row][new_col]=cnt[row][col]+1;
				//먹을 수 있을 때
				if(map[new_row][new_col]!=0 && shark_size>map[new_row][new_col]){
					if(min_dist > cnt[new_row][new_col]){
						min_row = new_row;
						min_col = new_col;
						min_dist = cnt[new_row][new_col];
					}
					else if(min_dist == cnt[new_row][new_col]){
						if(min_row==new_row){
							if(min_col > new_col){
								min_row=new_row;
								min_col=new_col;
							}
						}
						else if(min_row > new_row){
							min_row = new_row;
							min_col = new_col;
						}
					}
					
				}
				q.push({new_row,new_col});
					
				
			}
		}
	//cout<<"EATING FISH"<<endl;
		if(min_row!=21 && min_col!=21){
			eat++;
			//cout<<"MOVED: "<<cnt[min_row][min_col]<<endl;
			answer += cnt[min_row][min_col]-1;
			memset(cnt,0,sizeof(cnt));
			map[min_row][min_col]=0;
			cnt[min_row][min_col]++;
			if(eat==shark_size){
				shark_size++;
				//cout<<"SHARK_SIZE INCREASED TO: "<<shark_size<<endl;
				eat=0;
			}
			int q_size=q.size();
			for(int i = 0; i < q_size; i++) q.pop();
			q.push({min_row, min_col});
			//cout<<"SHARK_SIZE: "<<shark_size<<endl;
		}
		else break;
	}
	
	cout<<answer;
}