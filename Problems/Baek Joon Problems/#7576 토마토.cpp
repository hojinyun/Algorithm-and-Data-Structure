#include <iostream>
#include <queue>

using namespace std;

//���� ���� ���� �� ���������� ���� �丶�� ��ġ �� ������ �丶�� ���� 
int m=0, n=0, row=0, col=0, num_not_riped=0;
//�丶�� ��ġ ���� �� �� �丶�丶�� ���� ��¥�� �˱� ���� �迭 
int box[1000][1000]={0}, days[1000][1000]={0}; 
queue<pair<int,int>> q; //bfs�� ���� ť
//�̵� ������ 4����
int dx[4] = {0,0,1,-1};
int dy[4]={1,-1,0,0};

int main(){
	//�Է� 
	cin >> m >> n; 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> box[i][j];
			if(box[i][j] == 0) num_not_riped++; //������ �丶�� ���� 
			if(box[i][j] == 1) q.push({i,j}); //���� 
		}
	}
	while(!q.empty()){
		pair<int, int> tmp = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			if(num_not_riped==0) break;
			row = tmp.first+dx[i];
			col = tmp.second + dy[i];
			//�ڽ� ���� ���̰ų� �̹� ���� ��� �Ѿ 
			if(row<0 || row>=n || col<0 || col>=m || box[row][col]==1 || box[row][col]==-1) continue;
			
			q.push({row,col}); //ť�� ������ ��ġ ���� 
			box[row][col] = 1; //���� ���·� ��ȯ 
			num_not_riped--; //������ �丶�� ���� ���� 
			days[row][col]=days[tmp.first][tmp.second]+1; //�ڴµ� �ɸ��� �� ��		
		}
	}
	//��� 
	if(num_not_riped>0) cout<<-1;
	else cout<< days[row][col];
}
