#include <iostream>
#include <queue>

using namespace std;

int l, num_cases=0; //ü���� ũ�� �� ���̽� ���� 
int board[300][300]={0}, moves[300][300]={0}; //����
queue<pair<int,int>> q; //bfs�� ���� ť
pair<int,int> current_position = {0,0}, target_position = {0,0};
//�̵� ������ 8����
int dx[8] = {1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};

int main(){
	//�Է� 
	cin >> num_cases;
	while(num_cases--){
		cin >> l;
		cin >> current_position.first >> current_position.second;
		cin >> target_position.first >> target_position.second;
		//8���� ����� ��� Ȯ���ϴ� bfs ����
		//������ ����
		q.push({current_position.first,current_position.second});
		moves[current_position.first][current_position.second] = 1;
		while(!q.empty()){
			pair<int,int> tmp = q.front(); //ť ���� �տ� �� ����
			q.pop(); //ť ���� �տ� �� ����
			for(int i = 0; i < 8; i++){
				int row = tmp.first+dx[i], col = tmp.second + dy[i];
				//�̵��Ϸ��� ���� ���� ���̰ų� �湮�Ͽ����� ���� �������� �Ѿ
				//if(row==target_position.first && col==target_position.second) break;
				if(row<0 || row>=l || col<0 || col>=l || moves[row][col])  continue;
				//�̵��Ϸ��� ���� �̵��� �� �ִ� ĭ�� ��� ť�� �� ���� �� �迭�� ���� ����
				
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
		//��� 
		cout<< moves[target_position.first][target_position.second]-1<<'\n';
		//�� �ʱ�ȭ 
		for(int m = 0; m < l; m++){
			for(int n = 0; n < l; n++){
				moves[m][n]=0;
				board[m][n]=0;
			}
		}
	}
	
}
