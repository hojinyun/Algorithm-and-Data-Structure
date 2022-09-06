#include <iostream>

using namespace std;

bool visited[8] = {};
int n, W[10][10]={}, permutations[8]={}, sum=0, max_sum=0;

int brute_force(int x, int y){
	//입력한 길이만큼 채우면 계산 후 최대값과 비교하여 더 큰 값 저장 
	if(index==n){
		for(int i = 0, j = 1; i < n-1, j<n; i++,j++) sum+=ABS(permutations[i]-permutations[j]);
		min_sum=min(max_sum, sum);
		sum = 0; //저장하였으니 다시 0으로 초기화 
	}
	//백트래킹 
	for(int i = 0; i < n; i++){
		if(visited[i][j]) continue;
		visited[i][j] = true;
		permutations[index] = arr[i];
		brute_force(index+1);
		visited[i] = false;
		
	}
	return min_sum;	
}

int main(){
	//입력 
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> W[i][j];
		}
	} 
	//출력 
	cout<< brute_force(0);
}
