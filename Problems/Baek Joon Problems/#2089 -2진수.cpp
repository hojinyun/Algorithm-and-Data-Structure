#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n;
	stack<int> binary;
	//입력
	cin >> n;
	//0인 경우 예외 처리
	if(n==0){
		cout<<0;
		return 0;
	}
	//이진법으로 변환 연산
	while(n){ 
		//나머지가 1인 경우(홀수인 경우)
		if(n%-2) binary.push(1);
		//나머지가 0인 경우(짝수인 경우)
		else binary.push(0);
		//n이 양수여서 그대로 나누어 주면 되는 경우
		if(n>0) n/=-2;
		//n이 음수여서 짝수와 홀수로 나뉘는 경우
		else if(n<0){
			//음수인데 짝수인 경우 나누어 떨어지므로 그대로 나누기
			if(n%2==0) n=n/-2;
			//음수인데 홀수인 경우에는 -2로 나뉠 시 반내림이 되기 때문에 1을 더하여 반올림
			else n=n/-2+1;
		} 
	}
	//출력
	while(!binary.empty()){
		cout<<binary.top();
		binary.pop();
	}
}
