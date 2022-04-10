#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, stop,arr[10001]={};
	//�Է�
	cin >> n;
	for(int i = 1; i <=n; i++) cin >> arr[i];
	
	//�ڿ������� ������������ Ȯ�� 
	for(int i = n; i > 0; i--){
		//���� ó�� ������ Ȯ���� �Ϸ� �� ���̸�
		//�� �̻� ���� ������ �������� �����Ƿ� -1 ��� 
		if(i==1){
			cout<<-1;
			break;
		}
		//����� �Ǵ� ��ġ ã�� 
		if(arr[i-1]<arr[i]){
			//�ٲ�� �Ǵ� ���� ã�� 
			int stop = i-1; //���ߴ� ��ġ 
			int min_idx=i; //���� ������ ū ���� �ּ� �� �ʱ�ȭ
			//���� ��ġ���� ������ ��� �� Ȯ�� 
			for(int j = stop; j<=n; j++){
				//���� ������ ū ���߿� �ּҰ� min_idx�� ���� 
				if(arr[stop]<arr[j] && arr[j] < arr[min_idx]) min_idx = j;
			}
			
			//��ġ �ٲٰ� ���ߴ� ��ġ ���� �� ���� 
			int temp;
			temp = arr[min_idx];
			arr[min_idx] = arr[i-1];
			arr[i-1] = temp;
			sort(arr+i,arr+n+1);
			//��� 
			for(int i = 1; i<= n; i++) cout<<arr[i]<<" ";
			break;
		}
	}
}

/* next_permutation ��� ��� 
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, stop,arr[10001]={};
	//�Է�
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	if(next_permutation(arr,arr+n)){
		for(int i = 0; i<n; i++) cout<<arr[i]<<" ";
	}
	else cout<<-1;
}
*/
