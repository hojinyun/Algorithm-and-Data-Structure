//https://cocoon1787.tistory.com/333
#include <iostream>

using namespace std;

int n, num[20];
bool combinations[2000001]={0};

void brute_force(int index, int current){
	//전에 조합으로 나온 숫자 등록
	combinations[current] = true;
	//조합 할 수 있는 최대 횟수 달성 시 재귀 탈출
	if(index==n) return;
	//현재 값에서 인덱스만 올려서 재귀
	brute_force(index+1, current);
	//현재 값 더하기 인덱스 숫자 위치에 있는 숫자 후 재귀
	brute_force(index+1, current+num[index]);
}

int main(){
	//입력
	cin >> n;
	for(int i = 0; i < n; i++) cin >> num[i];
	
	//브루트포스 시작
	brute_force(0, 0);

	//출력
	int i = 0;
	while(combinations[i]==true) i++;
	cout<<i;
}
