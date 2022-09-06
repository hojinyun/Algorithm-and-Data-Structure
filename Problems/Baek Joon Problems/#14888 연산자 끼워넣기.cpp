#include <iostream>
#include <algorithm>
#define MAX 1000000001
#define MIN -1000000001

using namespace std;

int n=0, result = 0, maximum=MIN, minimum=MAX, numbers[10]={0}, operators[4]={0};

void brute_force(int index, int result){
	//모든 숫자를 다 확인하였으면 최대 최소값이면 저장
	if(index==n-1){
		maximum = max(maximum, result);
		minimum = min(minimum, result);
		return;
	}
	
	for(int i = 0; i < 4; i++){
		if(operators[i]==0) continue;

		int tmp_result = result; //결과 값 백업
		operators[i]--; //사용한 연산자 개수 줄이기
		//덧셈
		if(i==0){
			result+=numbers[index+1];
			brute_force(index+1, result);
		}
		//뺄셈
		else if(i==1){
			result-=numbers[index+1];
			brute_force(index+1, result);
		}
		//곱셈
		else if(i==2){
			result*=numbers[index+1];
			brute_force(index+1, result);
		}
		//나눗셈
		else if(i==3){
			result/=numbers[index+1];
			brute_force(index+1, result);
		}
		//사용한 연산자 개수 다시 올려주고 원래 결과 값 복구
		operators[i]++;
		result = tmp_result;
		
	}
	
}

int main(){
	//입력
	cin >> n;
	for(int i = 0; i < n; i++) cin >> numbers[i];
	for(int i = 0; i < 4; i++) cin >> operators[i];
	//시작 인덱스 및 첫번째 숫자로 브루트포스 시작
	brute_force(0, numbers[0]);
	//출력
	cout<<maximum<<"\n"<<minimum;
}