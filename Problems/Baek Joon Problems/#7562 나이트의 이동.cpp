#include <iostream>
#include <queue>

using namespace std;

int l, num_cases=0; //체스판 크기 및 케이스 개수 
int board[300][300]={0}, moves[300][300]={0}; //지도
queue<pair<int,int>> q; //bfs를 위한 큐
pair<int,int> current_position = {0,0}, target_position = {0,0};
//이동 가능한 8방향
int dx[8] = {1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};

int main(){
	//입력 
	cin >> num_cases;
	while(num_cases--){
		cin >> l;
		cin >> current_position.first >> current_position.second;
		cin >> target_position.first >> target_position.second;
		//8가지 방식을 모두 확인하는 bfs 시작
		//시작점 저장
		q.push({current_position.first,current_position.second});
		moves[current_position.first][current_position.second] = 1;
		while(!q.empty()){
			pair<int,int> tmp = q.front(); //큐 제일 앞에 값 저장
			q.pop(); //큐 제일 앞에 값 삭제
			for(int i = 0; i < 8; i++){
				int row = tmp.first+dx[i], col = tmp.second + dy[i];
				//이동하려는 값이 범위 밖이거나 방문하였으면 다음 방향으로 넘어감
				//if(row==target_position.first && col==target_position.second) break;
				if(row<0 || row>=l || col<0 || col>=l || moves[row][col])  continue;
				//이동하려는 값이 이동할 수 있는 칸인 경우 큐에 값 저장 및 배열에 깊이 저장
				
				q.push({row,col});
				moves[row][col]=moves[tmp.first][tmp.second]+1;
				//if(row==target_position.first && col==target_position.second) break;
			}
			/*
			cout<<"---------------------"<<endl;
			for(int j = 0; j < l; j++){
				for(int k = 0; k < l; k++){
					//if(j==target_position.first && k==target_position.second) cout<< "T "; 
					//else
					cout<<moves[j][k]<<" ";
				}
				cout<<endl;
			}*/
			
		}
		//출력 
		cout<< moves[target_position.first][target_position.second]-1<<'\n';
		//값 초기화 
		for(int m = 0; m < l; m++){
			for(int n = 0; n < l; n++){
				moves[m][n]=0;
				board[m][n]=0;
			}
		}
	}
	
}
