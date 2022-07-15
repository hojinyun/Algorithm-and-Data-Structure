#include <iostream>
#include <queue>

using namespace std;

int n, m; //가로 세로 길이
int check[100][100]={0}; //깊이 저장 및 방문 확인 을 위한 배열
char map[100][100]={0}; //지도
queue<pair<int,int>> q; //dfs를 위한 큐
//이동 가능한 4방향
int dx[4] = {0,0,1,-1};
int dy[4]={1,-1,0,0};

int main(){
	//입력 
	cin >> n >> m; 
	for(int i = 0; i < n; i++) cin >> map[i];
	//주위 4칸을 모두 확인하는 dfs 시작
	//시작점 저장
	q.push({0,0});
	check[0][0] = 1;
	while(!q.empty()){
		pair<int,int> tmp = q.front(); //큐 제일 앞에 값 저장
		q.pop(); //큐 제일 앞에 값 삭제
		for(int i = 0; i < 4; i++){
			int row = tmp.first+dx[i], col = tmp.second + dy[i];
			//이동하려는 값이 범위 밖이거나 방문하였으면 다음 방향으로 넘어감
			if(row<0 || row>=n || col<0 || col>=m || check[row][col])  continue;
			//이동하려는 값이 이동할 수 있는 칸인 경우 큐에 값 저장 및 배열에 깊이 저장
			if(map[row][col]=='1'){
				q.push({row,col});
				check[row][col]=check[tmp.first][tmp.second]+1;
			}
		}
	}
	//출력 
	cout<< check[n-1][m-1];
}
