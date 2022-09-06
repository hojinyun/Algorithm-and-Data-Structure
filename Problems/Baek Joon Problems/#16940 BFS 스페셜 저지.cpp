//https://astrid-dm.tistory.com/383
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n=0, answer[100001]={0};
vector<int> graph[100001];
queue<int> q;

bool compare(const int& a, const int& b){
	return answer[a] < answer[b];
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
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		q.push(tmp);
		answer[tmp]=i;
	}
	
	for(int i = 1; i <= n; i++){
		sort(graph[i].begin(), graph[i].end(), compare);
	}
	
	if(q.front() != 1){
		cout<<0;
		exit(0);
	}
	else{
		queue<int> temp;
		temp.push(1);
		q.pop();
		while(!temp.empty()){
			int pos = temp.front();
			temp.pop();
			for(int i: graph[pos]){
				if(i == q.front()){
					temp.push(q.front());
					q.pop();
				}
			} 
		}
	}
	if(q.empty()) cout <<1;
	else cout<<0;
}
