#include <iostream>

using namespace std;

int n, queue[10000] = {}, back_idx = -1;

void push(int number){
	for(int i = 0; i < n; i++){
		if(queue[i]==0){
			queue[i] = number;
			back_idx = i;
			break;
		}
		else continue;
	}
	return;
}

void pop(){
	if(back_idx == -1) cout << -1 << "\n";
	else{
		cout<< queue[0] << "\n";
		//pop�� ���� ������ ������ �ϳ��� ���ܿ��� �ݺ���
		for(int i = 0; i < back_idx; i++){
			queue[i] = queue[i+1];
			queue[i+1] = 0;
		}
		back_idx--;
		//����� ��쿡 ������ ���� ������ 0���� ó��
		if(back_idx == -1) queue[0] = 0;
	}
	return;
}

void size(){
	cout << back_idx+1 << "\n";
	return;
}

void empty(){
	if(back_idx == -1) cout << 1 <<"\n";
	else cout << 0 <<"\n";
	return;
}

void front(){
	if(back_idx == -1) cout << -1 <<"\n";
	else{
		cout<< queue[0] << "\n";
	}
	return;
}

void back(){
	if(back_idx == -1) cout << -1 <<"\n";
	else{
		cout<< queue[back_idx] << "\n";
	}
	return;
}

int main(void){
	cin >> n;
	for(int i = 0; i < n; i++){
		string temp;
		cin >> temp;
		if(temp == "push"){
			int number;
			cin >> number;
			push(number);
		}
		else if(temp == "pop") pop();
		else if(temp == "size") size();
		else if(temp == "empty") empty();
		else if(temp == "front") front();
		else if(temp == "back") back();
	}
	
}
