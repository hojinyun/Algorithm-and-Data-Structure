#include <iostream>

using namespace std;

bool visited[8] = {};
int n, W[10][10]={}, permutations[8]={}, sum=0, max_sum=0;

int brute_force(int x, int y){
	//�Է��� ���̸�ŭ ä��� ��� �� �ִ밪�� ���Ͽ� �� ū �� ���� 
	if(index==n){
		for(int i = 0, j = 1; i < n-1, j<n; i++,j++) sum+=ABS(permutations[i]-permutations[j]);
		min_sum=min(max_sum, sum);
		sum = 0; //�����Ͽ����� �ٽ� 0���� �ʱ�ȭ 
	}
	//��Ʈ��ŷ 
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
	//�Է� 
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> W[i][j];
		}
	} 
	//��� 
	cout<< brute_force(0);
}
