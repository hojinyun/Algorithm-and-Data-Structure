#include <iostream>

using namespace std;

int main(){
	int n;
	long long d[91] = {0, 1, 1};
	//�Է� 
	cin >> n;
	//�Ǻ���ġ ����
	for(int i = 3; i <= n; i++){
		d[i] = d[i-1]+d[i-2];
	}
	//��� 
	cout<<d[n];
}
