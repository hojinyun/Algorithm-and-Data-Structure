#include <iostream>
#include <stack>

using namespace std;

int main(){
	int A, B, m, dec=0;
	stack<int> answer;
	//ù��° �ٰ� �ι�° �� �Է�
	cin >> A >> B >> m;
	for(int i = 0; i < m; i++){
		int number;
		cin >> number;
		//A�������� 10�������� ��ȯ 
		dec = dec*A+number;
	}
	//10�������� B�������� ��ȯ 
	while(dec > 0) {
		answer.push(dec%B);
		//���ڸ� �ݳ������� ������ �� 
		dec /= B;
	}
	//���
	while(!answer.empty()){
		cout<<answer.top()<<" ";
		answer.pop();
	}
}
