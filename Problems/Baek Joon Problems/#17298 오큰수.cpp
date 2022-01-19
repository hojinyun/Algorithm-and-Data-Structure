#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n;
	stack<int> s, NGE, answer;
	//입력
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		s.push(temp);
	}

	while(!s.empty()){
		//제일 오른쪽 숫자가 아닐 때 
		if(!NGE.empty()){
			//오른쪽 숫자가 클 때 
			if(s.top() < NGE.top()){
				answer.push(NGE.top());
				NGE.push(s.top());
				s.pop(); 
			}
			//오른쪽 숫자가 작을 때 
			else{
				NGE.pop();
			}
		}
		//제일 오른쪽 숫자여서 NGE가 비어있을 때
		else{
			answer.push(-1);
			NGE.push(s.top());
			s.pop();
		}
	}
	//정답 출력
	for(int i = 0; i < n; i++){
		if(!answer.empty()){
			cout << answer.top() << " ";
			answer.pop();
		}
	}
}

/* O(N^2)으로 시간 초과 
#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	int numbers[n];
	for(int i = 0; i < n; i++) cin >> numbers[i];
	
	for(int i = 0; i < n; i++){
		if(i == n-1) cout << -1 <<" ";
		for(int j = i+1; j < n; j++){
			if(numbers[i] < numbers[j]){
				cout<<numbers[j]<<" ";
				break;
			}
			if(j == n-1) cout << -1 <<" ";
		}
	}
}
*/
