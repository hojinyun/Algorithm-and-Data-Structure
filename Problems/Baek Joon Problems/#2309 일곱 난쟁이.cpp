#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int sum=0, arr[9];
	//�Է� �� ��� �Է°��� �� ����
	for(int i = 0; i < 9; i++){
		cin >> arr[i];
		sum+=arr[i];
	}
	sort(arr,arr+9); //����
	//2���� ������ ������ ��� sum���� ���� �� 100�̸� -1�� �ٲ۴�
	for(int i = 0; i < 9; i++){
		for(int j = i+1; j < 9; j++){
			if(sum-arr[i]-arr[j]==100){
				arr[i] = arr[j] = -1;
				break; //���� ���� �������� �ߺ��� �� �� ������ 100�� �Ǵ� ���� ������ �ٷ� for�� Ż��
			}
		}
		//���� ���� �������� �ߺ��� �� �� ������ 100�� �Ǵ� ���� ������ �ٷ� for�� Ż��
		if(arr[i]==-1) break;
	}
	//���� �Ǵ� �� ���� ������ �� ���
	for(int i = 0; i < 9; i++){
		if(arr[i] != -1) cout << arr[i] <<'\n';
	}
	
}
