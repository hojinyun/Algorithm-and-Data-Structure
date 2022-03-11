#include <iostream>
#define MIN(a,b) (a<b ? a : b)

using namespace std;

int n, m, answer = 500001, counter = 0;
bool broken[10]={};

//모든 버튼을 누르는 경우의 수를 확인하는 재귀함수
void brute_force(string n_string){
	//0부터 9까지 모든 버튼 확인
	for(int i=0; i<10; i++){
		//고장난 버튼 제외하고 실행
		if(!broken[i]){
			//가능한 버튼 조합 생성
			string temp_n = n_string + to_string(i);
			//채널과 현재 조합된 숫자와의 거리+누른 버튼 수 
			answer = MIN(answer, abs(n-stoi(temp_n))+temp_n.length());
			//아직 6자리 안채웠다면 6자리 채울 때까지 더 해보기
			if(temp_n.length() < 6) brute_force(temp_n);
		} 
	}
}

int main(){
	//입력
	cin >> n;
	cin >> m;
	for(int i = 0; i < m; i++){
		int temp;
		cin >> temp;
		broken[temp] = true;
	}
	//100에서부터 +,-를 누르는 경우
	answer = min(answer, abs(n-100));
	//모든 버튼이 안되는 경우를 제외하고 모든 버튼의 경우의 수에
	//따른 거리 계산 함수 실행
	if(m!=10){
		brute_force("");
	}
	cout<<answer;
}
