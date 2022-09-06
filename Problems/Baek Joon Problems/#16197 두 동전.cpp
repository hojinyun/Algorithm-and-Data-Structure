#include <iostream>
#include <queue>

using namespace std;

struct Coin{
	int row1,col1,row2,col2,count;
};

bool visit[21][21][21][21]={0};
int n=0, m=0;
char board[21][21]={0};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
queue<Coin> q;

int main(){
	//입력
	cin >> n >> m;
	Coin tmp{-1,-1,-1,-1,1};
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> board[i][j];
			//코인 위치 저장
			if(board[i][j]=='o'){
				if(tmp.row1==-1) tmp.row1=i,tmp.col1=j;
				else tmp.row2=i,tmp.col2=j;
			}
		}
	}
	//코인 시작 위치 큐에 저장 및 방문처리
	q.push(tmp);
	visit[tmp.row1][tmp.col1][tmp.row2][tmp.col2] = 1;
	while(!q.empty()){
		Coin coin = q.front();
		q.pop();
		//10이 넘었을 경우 loop에서 탈출한 뒤 -1 출력
		if(coin.count>10) break;

		for(int i = 0; i < 4; i++){
			int new_coin1_row=coin.row1+dx[i], new_coin1_col=coin.col1+dy[i];
			int new_coin2_row=coin.row2+dx[i], new_coin2_col=coin.col2+dy[i];
			//코인 두개 다 떨어졌을 경우
			if((new_coin1_row<1||new_coin1_col<1||new_coin1_row>n||new_coin1_col>m)&&(new_coin2_row<1||new_coin2_col<1||new_coin2_row>n||new_coin2_col>m)) continue;
			//코인 중 한개만 밖으로 떨어졌을 때
			else if(new_coin1_row<1||new_coin1_row>n||new_coin1_col<1||new_coin1_col>m||new_coin2_row<1||new_coin2_row>n||new_coin2_col<1||new_coin2_col>m){
				cout<<coin.count;
				exit(0);
			}
			//이미 방문한 coin1과 coin2의 위치 조합인 경우 넘어감
			if(visit[new_coin1_row][new_coin1_col][new_coin2_row][new_coin2_col]) continue;
			//현재 위치 방문처리
			visit[new_coin1_row][new_coin1_col][new_coin2_row][new_coin2_col] = true;
			//두 코인 모두 벽에 막혔을 때
			if(board[new_coin1_row][new_coin1_col]=='#'&&board[new_coin2_row][new_coin2_col]=='#') continue;
			//코인1만 벽에 막혔을 때
			else if(board[new_coin1_row][new_coin1_col]=='#') q.push(Coin{coin.row1,coin.col1,new_coin2_row,new_coin2_col,coin.count+1});
			//코인2만 벽에 막혔을 때
			else if(board[new_coin2_row][new_coin2_col]=='#') q.push(Coin{new_coin1_row,new_coin1_col,coin.row2,coin.col2,coin.count+1});
			//두 코인 모두 움직일 때
			else q.push(Coin{new_coin1_row,new_coin1_col,new_coin2_row,new_coin2_col,coin.count+1});
				

		}
	}
	cout<<-1;
}