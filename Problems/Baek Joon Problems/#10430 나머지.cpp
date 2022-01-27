#include <iostream>

using namespace std;

int main(){
	int numbers[3];
	for(int i = 0; i < 3; i++){
		cin >> numbers[i];
	}
	cout << (numbers[0]+numbers[1])%numbers[2] << endl;
	cout << (numbers[0]%numbers[2]+numbers[1]%numbers[2])%numbers[2] << endl;
	cout << (numbers[0]*numbers[1])%numbers[2] << endl;
	cout << (numbers[0]%numbers[2]*numbers[1]%numbers[2])%numbers[2] << endl;
}
