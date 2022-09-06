#include <iostream>
#include <queue>

using namespace std;

bool visit[100001];
queue<pair<int, int> > q;
int N, K, answer;

bool check(int coord){
	if(coord < 0 || coord > 100000 || visit[coord]) return false;
	return true;
}

void bfs(int n){
	q.push({n,0});
	
	while(!q.empty()){
		int coord = q.front().first;
		int seconds = q.front().second;
		q.pop();
		if(coord == K){
			answer = seconds;
			break;
		}
		if(check(coord-1)){
			visit[coord-1] = true;
			q.push({coord-1, seconds+1});
		}
		if(check(coord+1)){
			visit[coord+1] = true;
			q.push({coord+1, seconds+1});
		}
		if(check(coord*2)){
			visit[coord*2] = true;
			q.push({coord*2, seconds+1});			
		}
		
	}
}

int main(void){
	cin >> N >> K;
	bfs(N);
	cout << answer;
	
}
