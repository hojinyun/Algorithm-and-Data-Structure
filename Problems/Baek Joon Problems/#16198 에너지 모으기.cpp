#include <iostream>
#include <algorithm>

using namespace std;

bool visited[10];
int n = 0, energy[10], maximum_energy=0;

void brute_force(int index, int total_energy){
	//재귀함수 탈출 조건
	if(index == n-2){
		//최대 에너지 값 저장
		maximum_energy = max(maximum_energy, total_energy);
		return;
	}
	//선택 가능한 에너지 구슬들 모두 확인
	for(int i = 1; i < n-1; i++){
		if(visited[i]) continue; //이미 사용한 에너지 구슬 무시
		int left_energy=0, right_energy=0; //선택한 위치 기준 왼쪽 오른쪽 에너지 구슬 선언
		visited[i]=true; //현재 선택한 위치 방문 처리
		//사용 가능한 왼쪽 에너지 구슬 탐색
		for(int j = i; j > -1; j--){
			if(visited[j]) continue;
			left_energy = energy[j];
			break;
		}
		//사용 가능한 오른쪽 에너지 구슬 탐색
		for(int j = i; j < n; j++){
			if(visited[j]) continue;
			right_energy = energy[j];
			break;
		}
		//한번 더 재귀함수에 들어갈 때 인덱스 올리고 계산한 에너지 총 값을 넘김
		brute_force(index+1, total_energy+left_energy*right_energy);
		//재귀함수 탈출 후 방문 처리 취소
		visited[i]=false;
	}
	
}

int main(){
	//입력
	cin >> n;
	for(int i = 0; i < n; i++) cin >> energy[i];
	//브루트포스 시작
	brute_force(0,0);
	//출력
	cout<<maximum_energy;
}