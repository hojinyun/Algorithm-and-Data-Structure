#include <iostream>

using namespace std;

bool answer = false;
int n=0, m=0, start_row = 0, start_col=0; //체스판 크기 및 케이스 개수
bool visited[50][50]={0};
char board[50][50]={0};
//이동 가능한 8방향
int dx[4] = {0,0,-1,1};
int dy[4]={-1,1,0,0};

void dfs(int row, int col, int cnt){
	if(visited[row][col] == true || answer==true) return;
	visited[row][col] = true;
	//cout<<row<<" "<<col<<endl;
	for(int i = 0; i < 4; i++){
		int new_row = row+dx[i], new_col = col+dy[i];
		if(start_row == new_row && start_col == new_col && cnt>=4){
			//cout<<"FOUND ANSWER"<<endl;
			answer = true;
			return;
		}
		if(new_row<0 || new_row>=n || new_col<0 || new_col>=m || visited[new_row][new_col] || board[start_row][start_col]!=board[new_row][new_col]){
			//cout<<"CONTINUE"<<endl;
			continue;
		}
		
		//cout<<"GOING DEEPER"<<endl;
		dfs(new_row, new_col, cnt+1);
	}
	visited[row][col]=false;
}

int main(){
	//입력 
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}
		
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(visited[i][j]) continue;
			//cout<<i<<" "<<j<<endl;
			start_row = i;
			start_col = j;
			dfs(i, j, 1);
		}
	}
	//cout<<start_row<<" "<<start_col<<endl;
	if(answer==true) cout<<"Yes";
	else cout<<"No";
	
}
