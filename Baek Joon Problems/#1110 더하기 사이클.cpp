#include <iostream>

using namespace std;

int main(void){
	int input;
	int add;
	int origin[2];
	int num[2];
	int counter = 1;
	
	cin >> input;
	
	//Sort out input less than 10 and split tenth and first
	if(input < 10){
		origin[0] = 0;
		origin[1] = input;
	}
	else{
		origin[0] = input / 10;
		origin[1] = input - origin[0]*10;
	}
	
	//Repeat cycle until num and origin are same while counting
	num[0] = origin[1];
	add = origin[0]+origin[1];
	num[1] = add - add/10*10;
	while(!(num[0] == origin[0] && num[1] == origin[1])){
		int addition = (num[0]+num[1]);
		num[0] = num[1];
		num[1] = addition - addition/10*10;
		counter++;
	}
	cout<< counter;
	
	return 0;
	
}
