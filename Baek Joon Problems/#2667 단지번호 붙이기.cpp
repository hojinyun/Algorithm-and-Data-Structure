#include <iostream>
#include <vector>

using namespace std;

int counter[25];
int c[25];
vector<int> map[25][25];

int main(void){
	int number;
	scanf("%d", &number);
	
	for(int i = 0; i < number; i++){
		for(int j= 0; j < number; j++){
			scanf("%1d", &map[i][j]);
		}
	}
	

	for(int i = 0; i < number; i++){
		for(int j= 0; j < number; j++){
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
}
