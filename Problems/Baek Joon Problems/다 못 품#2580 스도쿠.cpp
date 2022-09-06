#include <iostream>

using namespace std;

int board[9][9]={0};

bool num_exist(int row, int col, int num){
	for(int i = 0; i < 9; i++){
		if(i==row) continue;
		if(board[i][col]==num) return true;
	}
	for(int i = 0; i < 9; i++){
		if(i==col) continue;
		if(board[row][i]==num) return true;
	}
	return false;
}

void brute_force(int row, int col){
	cout<<"ROW: "<<row<<" COL: "<<col<<endl;
	if(row==9 && col==9) return;
	if(col==9){
		brute_force(row+1,0);
	}
	for(int i = 1; i <= 9; i++){
		if(board[row][col]!=0) continue;
		cout<<"CHECK: "<<i<<endl;
		board[row][col]=i;
		if(num_exist(row, col, i)){
			cout<<"EXISTS"<<endl;
			board[row][col]=0;
			continue;
		}
	}
	cout<<"FILL"<<endl;
	brute_force(row,col+1);
}

int main(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin >> board[i][j];
		}
	}
	brute_force(0,0);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << board[i][j] <<" ";
		}
		cout<<endl;
	}
	
}
