#include <iostream>

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	return gcd(b, a%b);
}

int main(void){
	int number;
	int numbers[2][1000];
	int answers[2][1000];
	int LCM;
	int GCD;
	cin >> number;
	
	for(int i = 0; i < number; i++){
		cin >> numbers[0][i];
		cin >> numbers[1][i];
	}
	for(int i = 0; i < number; i++){
		GCD = gcd(numbers[0][i], numbers[1][i]);
		LCM = numbers[0][i]*numbers[1][i]/GCD;
		answers[0][i] = LCM;
		answers[1][i] = GCD;
	}
	for(int i = 0; i < number; i++){
		cout << answers[0][i] << " ";
		cout << answers[1][i] << endl;
	}

} 
