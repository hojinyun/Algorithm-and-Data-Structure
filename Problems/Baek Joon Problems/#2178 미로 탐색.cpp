#include <iostream>
#include <queue>

using namespace std;

int n, m; //���� ���� ����
int check[100][100]={0}; //���� ���� �� �湮 Ȯ�� �� ���� �迭
char map[100][100]={0}; //����
queue<pair<int,int>> q; //dfs�� ���� ť
//�̵� ������ 4����
int dx[4] = {0,0,1,-1};
int dy[4]={1,-1,0,0};

int main(){
	//�Է� 
	cin >> n >> m; 
	for(int i = 0; i < n; i++) cin >> map[i];
	//���� 4ĭ�� ��� Ȯ���ϴ� dfs ����
	//������ ����
	q.push({0,0});
	check[0][0] = 1;
	while(!q.empty()){
		pair<int,int> tmp = q.front(); //ť ���� �տ� �� ����
		q.pop(); //ť ���� �տ� �� ����
		for(int i = 0; i < 4; i++){
			int row = tmp.first+dx[i], col = tmp.second + dy[i];
			//�̵��Ϸ��� ���� ���� ���̰ų� �湮�Ͽ����� ���� �������� �Ѿ
			if(row<0 || row>=n || col<0 || col>=m || check[row][col])  continue;
			//�̵��Ϸ��� ���� �̵��� �� �ִ� ĭ�� ��� ť�� �� ���� �� �迭�� ���� ����
			if(map[row][col]=='1'){
				q.push({row,col});
				check[row][col]=check[tmp.first][tmp.second]+1;
			}
		}
	}
	//��� 
	cout<< check[n-1][m-1];
}
