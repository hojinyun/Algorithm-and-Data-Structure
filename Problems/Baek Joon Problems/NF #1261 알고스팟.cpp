#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n=0, m=0, count[101][101]={0};
char map[101][101];
queue <pair<int,int>> q;

int main(){
	//입력 
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> map[i][j];
			count[i][j]=10000;
		}		
	}
	q.push({1,1});
	count[1][1] = 0;
	while(!q.empty()){
		int row = q.front().first; //큐 제일 앞에 값 저장
		int col = q.front().second;
	//	cout<<"----------------"<<endl;
		//cout<<"ROW: "<<row<<" COL: "<<col<<endl;
		q.pop(); //큐 제일 앞에 값 삭제
		for(int i = 0; i < 4; i++){
			int new_row = row+dx[i], new_col = col+dy[i];
			//cout<<"NEW_ROW: "<<new_row<<" NEW_COL: "<<new_col;
		/*	if(new_row==n && new_col==m){
				cout<<count[row][col];
				exit(0);
			}*/
			//이동하려는 값이 범위 밖이거나 방문하였으면 다음 방향으로 넘어감
			if(new_row<1 || new_row>n || new_col<1 || new_col>m) {
			//	cout<<" CONTINUE"<<endl;
				continue;
			}
			//이동하려는 값이 이동할 수 있는 칸인 경우 큐에 값 저장 및 배열에 깊이 저장
			if(map[new_row][new_col]=='1' && count[new_row][new_col]>count[row][col]+1){
				q.push({new_row,new_col});
				count[new_row][new_col]=count[row][col]+1;
				//cout<<" COUNT: "<<count[new_row][new_col]<<endl;
				
			}
			if(map[new_row][new_col]=='0' && count[new_row][new_col]>count[row][col]){
				q.push({new_row,new_col});
				count[new_row][new_col]=count[row][col];
			//	cout<<" COUNT: "<<count[new_row][new_col]<<endl;
			}
			
			/*
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= m; j++){
					cout << count[i][j];
				}	
				cout<<endl;
			}*/
		}
	}
	cout<<count[n][m];
}
