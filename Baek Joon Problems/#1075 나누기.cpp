#include <stdio.h>

using namespace std;


int main(void){
	int n, d;
	scanf("%d %d", &n, &d);
	
	n = (n/100)*100;
	
	while(n%d != 0){
		n++;
	}
	printf("%d", n);
	n %= 100;
	printf("%02d", n);
		
}
