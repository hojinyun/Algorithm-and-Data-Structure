#include <iostream>

using namespace std;

int n=0, count=0, board[14]={0};

//퀸을 놓을 수 있는지 확인 
bool check(int col){
	//확인하고 싶은 열 이전의 모든 열 확인 
	for(int i=0; i<col; i++){
		//열에 같은 행 값이 있거나 대각선인 경우(행의 차이와 열의 차이가 같은 경우) 
		if(board[col]==board[i] || col-i==abs(board[col]-board[i])) return false;
	}
	//모두 통과하였으니 true 반환 
	return true;
}

void brute_force(int col){
	//끝까지 다 확인하였으니 개수 1개 추가 
	if(col==n){
		count++;
		return;
	}
	//열에 모든 행의 값을 넣어본다 
	for(int row=0; row<n; row++){
		board[col]=row; //행의 값 대입 
		//행의 값 입력 가능하면 다음 열로 넘어간다 
		if(check(col)) brute_force(col+1);
	}
}

int main(){
	//입력 
	cin >> n;
	//모든 자리에 퀸을 넣어보는 경우의 수 
	brute_force(0);
	//출력 
	cout << count;
}
