#include <iostream>
#define LAND 1
#define SEA 0

using namespace std;

int w, h, cnt=0; //가로 세로 길이 및 땅의 개수 저장을 위한 int 자료형
bool map[50][50]={0}, visited[50][50]={0}; //지도 및 방문 확인을 위한 배열
//한 좌표에서 갈 수 있는 8가지 방향
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,0,1,-1,0,1,-1};

//인접 땅을 모두 확인하여 방문처리하는 dfs
void explore_land_dfs(int x, int y){
	if(visited[y][x]==true) return;
	visited[y][x]=true;
	//8가지 방향 모두 탐색
	for(int i = 0; i < 8; i++){
		//지도 범위 밖일 때  
		if(x+dx[i]<0 || x+dx[i]>=w || y+dy[i]<0 || y+dy[i]>=h) continue;
		//인근 땅을 발견 했을 때
		if(map[y+dy[i]][x+dx[i]]==LAND && visited[y+dy[i]][x+dx[i]]==false) explore_land_dfs(x+dx[i],y+dy[i]);
	}
}

int main(){
	while(true){
		//입력 
		cin >> w >> h; 
		if(w==0 && h==0) break;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> map[i][j];
			}
		} 
		//땅일때 dfs로 인접한 땅 모두 확인 
		for(int k = 0; k < h; k++){
			for(int l = 0; l < w; l++){
				if(map[k][l]==LAND&&visited[k][l]==false){
					explore_land_dfs(l, k);
					cnt++;
				}
			}
		}
		//출력 
		cout<< cnt << '\n';
		//값 초기화 
		cnt = 0;
		for(int m = 0; m < 50; m++){
			for(int n = 0; n < 50; n++){
				visited[m][n]=0;
				map[m][n]=0;
			}
		}
	}
}
