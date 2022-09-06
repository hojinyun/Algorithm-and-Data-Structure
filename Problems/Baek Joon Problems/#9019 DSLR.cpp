#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

bool visited[10001]={0};
int t, initial_num, target_num;

int main(){
	//입력 
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> initial_num >> target_num;
		//BFS
		//큐에 현재 연산한 숫자와 사용한 커맨드 저장 
		queue<pair<int,string>> q;
		//처음 시작 숫자 큐에 저장 
		q.push({initial_num,""});
		visited[initial_num]=true;
		while(!q.empty()){
			//큐에서 숫자와 커맨드 추출 후 팝 
			int num=q.front().first;
			string command=q.front().second;
			q.pop();
			//목표 숫자에 도달했을 경우 출력 후 while문 탈출 
			if(num==target_num){
				cout<<command<<'\n';
				break;
			}
			//D 연산 후 방문 확인 
			int cal_num = (2*num)%10000;
			if(!visited[cal_num]){
				//방문처리
				visited[cal_num]=true;
				//큐에 연산 숫자 저장 및 커맨드 저장 
				q.push({cal_num,command+"D"});
			}
			//S 연산 후 방문 확인 
			cal_num = (num-1<0) ? 9999:num-1;
			if(!visited[cal_num]){
				visited[cal_num]=true;
				q.push({cal_num,command+"S"});
			}
			//L 연산 후 방문 확인 
			cal_num = (num%1000)*10 + num/1000;
			if(!visited[cal_num]){
				visited[cal_num]=true;
				q.push({cal_num,command+"L"});
			}
			//R 연산 후 방문 확인 
			cal_num = (num%10)*1000 + num/10;
			if(!visited[cal_num]){
				visited[cal_num]=true;
				q.push({cal_num,command+"R"});
			}
		}
		//방문 확인 배열 초기화 
		memset(visited,false,sizeof(visited));
	}
	
}
