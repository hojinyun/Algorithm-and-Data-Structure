//https://astrid-dm.tistory.com/383
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n=0, priority[100001]={0};
bool visited[100001]={0};
vector<int> graph[100001];
queue<int> answer;

bool compare(const int& a, const int& b){
	return priority[a] < priority[b];
}

void dfs(int x) {
	/*cout<<"-----Answer-----"<<endl;
	for(int i = 1; i <= n; i++){
		cout<<answer.front()<<" ";
		answer.pop();
	}*/
//	cout<<"ON: "<<x<<endl;
	if(answer.front()==x){
	//	cout<<"pop"<<endl;
		answer.pop();
	}
    if (visited[x]){
    //	cout<<"visited"<<endl;
    	return;
	}
    visited[x] = true;
    
    for(int y: graph[x]) {
    //	cout<<"IN FOR LOOP"<<endl;
        if (visited[y]) continue;
        dfs(y);
    }
}

int main(){
	//ют╥б 
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}
	
	for(int i = 1; i <= n; i++){
		int tmp;
		cin >> tmp;
		priority[tmp]=i;
		answer.push(tmp);
	}
	for(int i = 1; i <= n; i++){
		sort(graph[i].begin(), graph[i].end(), compare);
	}
	
	
	dfs(1);
	
	if(answer.empty()) cout<<1;
	else cout<<0;
}
