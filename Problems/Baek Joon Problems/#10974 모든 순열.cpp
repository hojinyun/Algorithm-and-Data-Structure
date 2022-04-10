#include <iostream>

using namespace std;


bool visited[8]={}; //사용 중인 숫자 확인 
int n, answer[8]={}; //입력값 및 순열 저장 배열 

void brute_force(int index){
	//길이 다 채우면 저장 된 값 출력 
	if(index==n){
		for(int i = 0; i<n; i++) cout<<answer[i]<<" ";
		cout<<"\n";
		return;
	}
	//백트래킹 
	for(int i = 1; i <= n; i++){
		if(visited[i]) continue; //이미 사용중인 수이면 넘긴다 
		visited[i]=true; //사용 중인 값으로 변환 
		answer[index]=i; //정답 배열에 값 저장 
		brute_force(index+1); //다음 인덱스로 넘어간다 
		answer[index]=0; //안해줘도 되지만 혹시 모르니 0으로 다시 초기화 
		visited[i]=false; //사용 중이지 않은 값으로 변환 
	}
}

int main(){
	//입력 
	cin >> n;
	//브루트포스 알고리즘 실행 
	brute_force(0);
}
