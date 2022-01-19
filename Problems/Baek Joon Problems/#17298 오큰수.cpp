#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n;
	stack<int> s, NGE, answer;
	//�Է�
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		s.push(temp);
	}

	while(!s.empty()){
		//���� ������ ���ڰ� �ƴ� �� 
		if(!NGE.empty()){
			//������ ���ڰ� Ŭ �� 
			if(s.top() < NGE.top()){
				answer.push(NGE.top());
				NGE.push(s.top());
				s.pop(); 
			}
			//������ ���ڰ� ���� �� 
			else{
				NGE.pop();
			}
		}
		//���� ������ ���ڿ��� NGE�� ������� ��
		else{
			answer.push(-1);
			NGE.push(s.top());
			s.pop();
		}
	}
	//���� ���
	for(int i = 0; i < n; i++){
		if(!answer.empty()){
			cout << answer.top() << " ";
			answer.pop();
		}
	}
}

/* O(N^2)���� �ð� �ʰ� 
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
