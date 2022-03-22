#include <iostream>

using namespace std;

//이동 방향을 위한 배열
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

int n, m, answer = 0, arr[500][500];
bool visited[500][500];

//재귀함수를 이용하여 모든 경우의 수 확인
void brute_force(int y, int x, int sum, int cnt){
	//끝까지 도달한 경우
	if(cnt == 4){
		answer = max(answer, sum);
		return;
	}
	//범위 밖을 벗어난 경우
	if(x<0 || y<0 || x>=m || y>=n) return;
	//이미 방문한 상태인 경우
	if(visited[y][x]) return;
	//백트래킹 
	visited[y][x] = true; //현재 도착점을 방문한 곳으로 지정
	//모든 4가지 방향 고려하여 이동
	for(int i = 0; i < 4; i++) brute_force(y+dy[i],x+dx[i],sum+arr[y][x],cnt+1);
	//확인 끝난 자리는 다시 방문하지 않는 곳으로 바꿈
	visited[y][x] = false;	
}

int main(){
	//입력
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cin >> arr[i][j];
	}
	//모든 모양 확인
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			brute_force(i, j, 0, 0); //ㅜ모양을 제외한 모든 경우의 수의 합 출력
			//ㅗ,ㅜ 모양 예외 처리 
			if(j+2<m){
				int temp_sum = arr[i][j]+arr[i][j+1]+arr[i][j+2];
				//ㅗ모양이 가능한지 확인 
				if(i-1>=0) answer=max(answer,temp_sum+arr[i-1][j+1]);
				//ㅜ모양이 가능한지 확인 
				if(i+1<n) answer=max(answer,temp_sum+arr[i+1][j+1]);
			}
			//ㅓ,ㅏ모양 예외 처리 
			if(i+2<n){
				int temp_sum = arr[i][j]+arr[i+1][j]+arr[i+2][j];
				//ㅓ모양이 가능한지 확인 
				if(j-1>=0) answer=max(answer,temp_sum+arr[i+1][j-1]);
				//ㅏ모양이 가능한지 확인 
				if(j+1<m) answer=max(answer,temp_sum+arr[i+1][j+1]);
			}
		}
	}
	//출력 
	cout<<answer;
}