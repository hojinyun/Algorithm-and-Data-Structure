#include <iostream>

using namespace std;

int main(){
	string numbers[4];
	long long answer = 0;
	//�Է� 
	for(int i=0; i < 4; i++){
		cin >> numbers[i];
	}
	//1��° 2��° ���� ��ġ�� ���� 
	answer += stoll(numbers[0]+numbers[1]);
	//3��° 4��° ���� ��ġ�� �� �տ� ��ģ ���� �� ���ֱ� 
	answer += stoll(numbers[2]+numbers[3]);
	//��� 
	cout<<answer;
}
