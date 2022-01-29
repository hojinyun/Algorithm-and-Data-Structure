#include <iostream>

using namespace std;

int main(){
	int n, answer = 0;
	//입력
	cin >> n;
	//n에서 하나씩 빼면서 5를 약수로 몇개 갖고 있는지 확인 
	while(n){
		if(!(n%125)) answer+=3; //5^3이므로 +3 
		else if(!(n%25)) answer+=2; //5^2이므로 +2
		else if(!(n%5)) answer+=1; //5^1이므로 +1
		n--;
	}
	//출력 
	cout<<answer;
}
