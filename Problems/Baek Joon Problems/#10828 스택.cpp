#include <iostream>

using namespace std;

int n, stack[10000] = {}, pop_idx = -1;

void push(int number){
	for(int i = 0; i <n; i++){
		if(stack[i]==0){
			stack[i] = number;
			pop_idx = i;
			break;
		}
		else continue;
	}
	return;
}

void pop(){
	if(pop_idx == -1) cout << -1 << "\n";
	else{
		cout<< stack[pop_idx] << "\n";
		stack[pop_idx] = 0;
		pop_idx--;
	}
	return;
}

void size(){
	cout << pop_idx+1 << "\n";
	return;
}

void empty(){
	if(pop_idx == -1) cout << 1 <<"\n";
	else cout << 0 <<"\n";
	return;
}

void top(){
	if(pop_idx == -1) cout << -1 <<"\n";
	else{
		cout<< stack[pop_idx] << "\n";
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
		else if(temp == "top") top();
	}
	
}
