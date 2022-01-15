#include <iostream>
#include <queue>

using namespace std;

int main(void){
	queue<int> q;
	queue<int> answer;
	int n, k;
	cin >> n;
	cin >> k;
	
	//큐에 1부터 n까지의 수 모두 넣기
	for(int i = 1; i <= n; i++){
		q.push(i);
	}
	
	//매 k번째마다 출력 아닐 경우는 큐로 다시 push 후 pop
	cout<<"<";
	while(!q.empty()){
		for(int i = 1; i < k; i++){
			q.push(q.front());
			q.pop();
		}
	//마지막 한개 남았을 경우 ',' 없이 출력
		if(q.size()==1) cout<<q.front();
		else cout<<q.front()<<", ";
		q.pop();
	}
	cout<<">";
}
