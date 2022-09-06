#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n=0, m=0, count[101][101]={0};
char map[101][101];
queue <pair<int,int>> q;

int main(){
	//�Է� 
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
		int row = q.front().first; //ť ���� �տ� �� ����
		int col = q.front().second;
	//	cout<<"----------------"<<endl;
		//cout<<"ROW: "<<row<<" COL: "<<col<<endl;
		q.pop(); //ť ���� �տ� �� ����
		for(int i = 0; i < 4; i++){
			int new_row = row+dx[i], new_col = col+dy[i];
			//cout<<"NEW_ROW: "<<new_row<<" NEW_COL: "<<new_col;
		/*	if(new_row==n && new_col==m){
				cout<<count[row][col];
				exit(0);
			}*/
			//�̵��Ϸ��� ���� ���� ���̰ų� �湮�Ͽ����� ���� �������� �Ѿ
			if(new_row<1 || new_row>n || new_col<1 || new_col>m) {
			//	cout<<" CONTINUE"<<endl;
				continue;
			}
			//�̵��Ϸ��� ���� �̵��� �� �ִ� ĭ�� ��� ť�� �� ���� �� �迭�� ���� ����
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
