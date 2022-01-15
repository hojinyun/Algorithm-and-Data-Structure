#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n, j = 0, number[100000];
queue<char> answer;
stack<int> s;


int main(){
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> number[i];
	
	for(int i = 1; i <= n; i++){
		s.push(i);
		answer.push('+');
		while(!s.empty() && s.top() == number[j]){
			s.pop();
			answer.push('-');
			j++;
		}
	}
	
	if(s.empty()){
		while (!answer.empty()){
		    cout << answer.front() << '\n';
		    answer.pop();
	  	}
  	}
  	else cout << "NO";
}	
