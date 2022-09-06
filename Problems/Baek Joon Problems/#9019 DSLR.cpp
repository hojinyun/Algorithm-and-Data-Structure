#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

bool visited[10001]={0};
int t, initial_num, target_num;

int main(){
	//�Է� 
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> initial_num >> target_num;
		//BFS
		//ť�� ���� ������ ���ڿ� ����� Ŀ�ǵ� ���� 
		queue<pair<int,string>> q;
		//ó�� ���� ���� ť�� ���� 
		q.push({initial_num,""});
		visited[initial_num]=true;
		while(!q.empty()){
			//ť���� ���ڿ� Ŀ�ǵ� ���� �� �� 
			int num=q.front().first;
			string command=q.front().second;
			q.pop();
			//��ǥ ���ڿ� �������� ��� ��� �� while�� Ż�� 
			if(num==target_num){
				cout<<command<<'\n';
				break;
			}
			//D ���� �� �湮 Ȯ�� 
			int cal_num = (2*num)%10000;
			if(!visited[cal_num]){
				//�湮ó��
				visited[cal_num]=true;
				//ť�� ���� ���� ���� �� Ŀ�ǵ� ���� 
				q.push({cal_num,command+"D"});
			}
			//S ���� �� �湮 Ȯ�� 
			cal_num = (num-1<0) ? 9999:num-1;
			if(!visited[cal_num]){
				visited[cal_num]=true;
				q.push({cal_num,command+"S"});
			}
			//L ���� �� �湮 Ȯ�� 
			cal_num = (num%1000)*10 + num/1000;
			if(!visited[cal_num]){
				visited[cal_num]=true;
				q.push({cal_num,command+"L"});
			}
			//R ���� �� �湮 Ȯ�� 
			cal_num = (num%10)*1000 + num/10;
			if(!visited[cal_num]){
				visited[cal_num]=true;
				q.push({cal_num,command+"R"});
			}
		}
		//�湮 Ȯ�� �迭 �ʱ�ȭ 
		memset(visited,false,sizeof(visited));
	}
	
}
