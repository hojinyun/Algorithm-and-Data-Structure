#include <iostream>

using namespace std;

int n, counter = 1, answer=0;
char board[51][51]={}, temp[51][51]={};

//입력 받은 board 배열 값들 temp에 복사
void initialize_board(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) temp[i][j] = board[i][j];
	}
}
//현재 자리와 같은 연속 된 가로 값들을 찾음
void count_horizontal_max(int row, int col){
	//오른쪽에 같은 값이 있는 경우
	for(int k = col+1; k <= n; k++){
		//다른 값이 나오는 경우 바로 for문 탈출
		if(temp[row][col]!=temp[row][k]) break;
		counter++;
	}
	//왼쪽으로 같은 값이 있는 경우
	for(int k = col-1; k > 0; k--){
		//다른 값이 나오는 경우 바로 for문 탈출
		if(temp[row][col]!=temp[row][k]) break;
		counter++;
	}
	answer = max(answer,counter);
	counter = 1;
}
//현재 자리와 같은 연속 된 세로 값들을 찾음
void count_vertical_max(int row, int col) {
	//아래로 같은 값이 있는 경우
	for(int k = row+1; k <= n; k++){
		//다른 값이 나오는 경우 바로 for문 탈출
		if(temp[row][col]!=temp[k][col])break;
		counter++;
	}
	//위로 같은 값이 있는 경우
	for(int k = row-1; k > 0; k--){
		//다른 값이 나오는 경우 바로 for문 탈출
		if(temp[row][col]!=temp[k][col]) break;
		counter++;
	}
	answer = max(answer,counter);
	counter = 1;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) cin >> board[i][j];
	}
	initialize_board();
	//1부터 n까지 좌우 위아래 모든 값을 다 바꿔서 확인 해봄
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			//아래값이 존재하고 다를 경우 바꿈
			if(board[i][j]!=board[i+1][j] && i+1<=n){
				//배열 값 변환
				char swap = temp[i][j];
				temp[i][j] = temp[i+1][j];
				temp[i+1][j] = swap;
				count_horizontal_max(i, j); //현재 확인 중인 값의 가로 최대 길이 확인
				count_horizontal_max(i+1, j); //아래줄도 바뀌었으니 가로 최대 길이 확인
				count_vertical_max(i,j); //세로로 값을 바꾸었으니 현재 확인 중인 값의 세로 최대 길이 확인
			}
			initialize_board(); //배열 값 변환하였으니 보드 초기화
			//오른쪽 값이 존재하고 다를 경우 바꿈
			if(board[i][j]!=board[i][j+1] && j+1<=n){
				//배열 값 변환
				char swap = temp[i][j];
				temp[i][j] = temp[i][j+1];
				temp[i][j+1] = swap;
				count_vertical_max(i,j); //현재 확인 중인 값의 세로 최대 길이 확인
				count_vertical_max(i,j+1); //오른쪽 줄도 바뀌었으니 세로 최대 길이 확인
				count_horizontal_max(i,j); //가로로 값을 바꾸었으니 현재 확인 중인 값의 가로 최대 길이 확인
			}
			initialize_board(); //배열 값 변환하였으니 보드 초기화
			count_horizontal_max(i, j); //배열 값을 변환 안하였을 때 가로 최대 길이 확인
			count_vertical_max(i,j); //배열 값을 변환 안하였을 때 세로 최대 길이 확인
		}
	}
	//출력
	cout<<answer;
}
