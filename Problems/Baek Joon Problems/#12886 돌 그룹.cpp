#include <iostream>
#include <queue>

using namespace std;

bool visit[1500][1500]={0};
int a, b, c, sum;
queue<pair<int,int>> q;


int main(){
	//입력 
	cin >> a >> b >> c;
	//두 숫자 선택 후 합을 이용하여 남은 숫자 하나 도출 
	sum=a+b+c;
	//삼등분이 애초에 불가능한 경우 
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
		//모든 숫자에 대하여 연산 시도 및 방문처리 
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
