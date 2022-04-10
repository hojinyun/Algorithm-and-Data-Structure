#include <iostream>
#define ABS(x)((x)>0 ? x:-(x))

using namespace std;

bool visited[8] = {};
int n, arr[8], permutations[8]={}, sum=0, max_sum=0;

int brute_force(int index){
	//�Է��� ���̸�ŭ ä��� ��� �� �ִ밪�� ���Ͽ� �� ū �� ���� 
	if(index==n){
		for(int i = 0, j = 1; i < n-1, j<n; i++,j++) sum+=ABS(permutations[i]-permutations[j]);
		max_sum=max(max_sum, sum);
		sum = 0; //�����Ͽ����� �ٽ� 0���� �ʱ�ȭ 
	}
	//��Ʈ��ŷ 
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
	//�Է� 
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	//��� 
	cout<< brute_force(0);
}
