#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int n=0, k=0;
int previous[100001]={0}, count[100001]={0};
queue<int> q;
stack<int> answer;

int main(){
	//ют╥б 
	cin >> n >> k;
	q.push(n);
	count[n]=1;
	while(!q.empty()){
		if(q.front()==k) break;
		int tmp = q.front();
		q.pop();
		if(count[tmp-1]==0 && tmp-1 >= 0){
			q.push(tmp-1);
			count[tmp-1] = count[tmp]+1;
			previous[tmp-1] = tmp;
		}
		if(count[tmp+1]==0 && tmp+1 <= 100000){
			q.push(tmp+1);
			count[tmp+1] = count[tmp]+1;
			previous[tmp+1] = tmp;
		}
		if(count[2*tmp]==0 && 2*tmp <= 100000){
			q.push(2*tmp);
			count[2*tmp] = count[tmp]+1;
			previous[2*tmp] = tmp;
		}
	}
	int tmp = previous[k];
	answer.push(k);
	for(int i = 0; i < count[k]-1; i++){
		answer.push(tmp);
		tmp = previous[tmp];
	}
	cout<<count[k]-1<<'\n';
	int stack_size = answer.size();
	for(int i = 0; i < stack_size; i++){
		cout<<answer.top()<<" ";
		answer.pop();
	}
}
