#include <iostream>

using namespace std;

int n, deque[10000] = {}, back_idx = -1;

void push_front(int number){
	if(back_idx != -1){
		//모든 값들 한칸 오른쪽으로 이동
		for(int i = back_idx; i > -1; i--){
			deque[i+1] = deque[i];
		}
	}
	deque[0] = number;
	back_idx++;
	return;
}

void push_back(int number){
	for(int i = 0; i < n; i++){
		if(deque[i]==0){
			deque[i] = number;
			back_idx = i;
			break;
		}
		else continue;
	}
	return;
}

void pop_front(){
	if(back_idx == -1) cout << -1 << "\n";
	else{
		cout<< deque[0] << "\n";
		//pop한 이후 앞으로 값들을 하나씩 땡겨오는 반복문
		for(int i = 0; i < back_idx; i++){
			deque[i] = deque[i+1];
			deque[i+1] = 0;
		}
		back_idx--;
		//비웠을 경우에 마지막 남은 값까지 0으로 처리
		if(back_idx == -1) deque[0] = 0;
	}
	return;
}
void pop_back(){
	if(back_idx == -1) cout << -1 << "\n";
	else{
		cout<< deque[back_idx] << "\n";
		deque[back_idx] = 0;
		back_idx--;
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
		cout<< deque[0] << "\n";
	}
	return;
}

void back(){
	if(back_idx == -1) cout << -1 <<"\n";
	else{
		cout<< deque[back_idx] << "\n";
	}
	return;
}

int main(void){
	cin >> n;
	for(int i = 0; i < n; i++){
		string temp;
		cin >> temp;
		if(temp == "push_front"){
			int number;
			cin >> number;
			push_front(number);
		}
		else if(temp == "push_back"){
			int number;
			cin >> number;
			push_back(number);
		}
		else if(temp == "pop_front") pop_front();
		else if(temp == "pop_back") pop_back();
		else if(temp == "size") size();
		else if(temp == "empty") empty();
		else if(temp == "front") front();
		else if(temp == "back") back();
	}
	
}
