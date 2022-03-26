#include <iostream>

using namespace std;

int n, m, answer[8]={};

void brute_force(int index){
	//끝에 도착하면 정답 출력 후 인덱스 한칸 "퇴각"
	if(index == m){
		for(int i = 0; i < m; i++) cout<<answer[i]<<" ";
		cout<<'\n';
		return;
	}
	//1부터 n까지 모든 수를 넣기 위한 for문
	for(int i = 1; i <= n; i++){
		//자신보다 작은 수가 뒤에 올려고 하는 경우 무시하고 다음 수로 넘어간다
		if(i<answer[index-1]) continue;
		answer[index] = i; //알맞는 값 저장
		brute_force(index+1); //다음 칸으로 넘어간다
		answer[index] = 0; //"퇴각"하였으니 0으로 초기화
	}
}
int main(){
	//입력
	cin >> n >> m;
	//재귀함수 시작
	brute_force(0);
}