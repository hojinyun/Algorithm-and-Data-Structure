#include <iostream>
#include <queue>

using namespace std;

bool visit[1500][1500]={0};
int a, b, c, sum;
queue<pair<int,int>> q;


int main(){
	//�Է� 
	cin >> a >> b >> c;
	//�� ���� ���� �� ���� �̿��Ͽ� ���� ���� �ϳ� ���� 
	sum=a+b+c;
	//������ ���ʿ� �Ұ����� ��� 
	if(sum%3!=0){
		cout<<0;
		return 0;
	}
	//BFS 
	q.push({a,b});
	visit[a][b]=true;
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		int temp[3]={x,y,sum-x-y};
		q.pop();
		//��� ���ڿ� ���Ͽ� ���� �õ� �� �湮ó�� 
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(temp[i]<temp[j]){
					if(visit[temp[i]*2][temp[j]-temp[i]]) continue;
					q.push({temp[i]*2,temp[j]-temp[i]});
					visit[temp[i]*2][temp[j]-temp[i]]=true;
				}
			}
		}
	}
	cout<<visit[sum/3][sum/3];
}
