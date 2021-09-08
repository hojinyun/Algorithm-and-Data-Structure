#include <stdio.h>

int d[1001];

int dp(int x){
	if(x == 1) return 1;
	if(x == 2) return 3;
	if(d[x] != 0) return d[x];
	//return d[x] = (dp(x-1) + dp(x-2)) % 10007;  <-- First Problem
	return d[x] = (dp(x-1) + 2*dp(x-2)) % 10007;
}


int main(void){
	int number;
	scanf("%d", &number);
	printf("%d", dp(number));
}
