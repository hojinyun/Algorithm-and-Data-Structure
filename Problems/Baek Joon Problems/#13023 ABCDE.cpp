#include <iostream>
#include <vector>

using namespace std;

bool visit[2000]={false};
vector<int> v[2000];

void dfs(int x, int cnt){
	visit[x] = true;
	if(cnt == 4){
		cout<< 1;
		exit(0);
	}
	for(int i: v[x]){
		if(!visit[i]) dfs(i, cnt+1);
	}
	visit[x] = false;
}

int main(){
	int n, m , a, b;
	//입력 
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	} 
	for(int i = 0; i < n; i++){
		dfs(i,0);
	}
	//출력 
	cout<< 0;
}
