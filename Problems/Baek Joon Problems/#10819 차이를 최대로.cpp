#include <iostream>
#define ABS(x)((x)>0 ? x:-(x))

using namespace std;

bool visited[8] = {};
int n, arr[8], permutations[8]={}, sum=0, max_sum=0;

int brute_force(int index){
	//입력한 길이만큼 채우면 계산 후 최대값과 비교하여 더 큰 값 저장 
	if(index==n){
		for(int i = 0, j = 1; i < n-1, j<n; i++,j++) sum+=ABS(permutations[i]-permutations[j]);
		max_sum=max(max_sum, sum);
		sum = 0; //저장하였으니 다시 0으로 초기화 
	}
	//백트래킹 
	for(int i = 0; i < n; i++){
		if(visited[i]) continue;
		visited[i] = true;
		permutations[index] = arr[i];
		brute_force(index+1);
		visited[i] = false;
		
	}
	return max_sum;	
}

int main(){
	//입력 
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	//출력 
	cout<< brute_force(0);
}
