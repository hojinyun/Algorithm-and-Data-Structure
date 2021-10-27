#include <iostream>

using namespace std;

int n, m, c[9], a[9];

void brute_force(int index){
	if(index == m){
		for(int i = 0; i < m; i++){
			cout << a[i] << " ";
		} 
		cout << "\n";
		return;
	}
	for(int i = 1; i <= n; i++){
		if(c[i]) continue;
		a[index] = i;
		c[i] = 1;
		brute_force(index+1);
		c[i] = 0;
		a[index] = 0;
	}
}

int main(void){
	cin >> n;
	cin >> m;
	brute_force(0);
	
}
