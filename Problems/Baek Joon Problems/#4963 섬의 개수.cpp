#include <iostream>
#define LAND 1
#define SEA 0

using namespace std;

int w, h, cnt=0; //���� ���� ���� �� ���� ���� ������ ���� int �ڷ���
bool map[50][50]={0}, visited[50][50]={0}; //���� �� �湮 Ȯ���� ���� �迭
//�� ��ǥ���� �� �� �ִ� 8���� ����
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,0,1,-1,0,1,-1};

//���� ���� ��� Ȯ���Ͽ� �湮ó���ϴ� dfs
void explore_land_dfs(int x, int y){
	if(visited[y][x]==true) return;
	visited[y][x]=true;
	//8���� ���� ��� Ž��
	for(int i = 0; i < 8; i++){
		//���� ���� ���� ��  
		if(x+dx[i]<0 || x+dx[i]>=w || y+dy[i]<0 || y+dy[i]>=h) continue;
		//�α� ���� �߰� ���� ��
		if(map[y+dy[i]][x+dx[i]]==LAND && visited[y+dy[i]][x+dx[i]]==false) explore_land_dfs(x+dx[i],y+dy[i]);
	}
}

int main(){
	while(true){
		//�Է� 
		cin >> w >> h; 
		if(w==0 && h==0) break;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> map[i][j];
			}
		} 
		//���϶� dfs�� ������ �� ��� Ȯ�� 
		for(int k = 0; k < h; k++){
			for(int l = 0; l < w; l++){
				if(map[k][l]==LAND&&visited[k][l]==false){
					explore_land_dfs(l, k);
					cnt++;
				}
			}
		}
		//��� 
		cout<< cnt << '\n';
		//�� �ʱ�ȭ 
		cnt = 0;
		for(int m = 0; m < 50; m++){
			for(int n = 0; n < 50; n++){
				visited[m][n]=0;
				map[m][n]=0;
			}
		}
	}
}
