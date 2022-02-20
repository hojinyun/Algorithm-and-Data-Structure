#include <iostream>

using namespace std;

int arr[1000], d[1000]={}, link[1000]={};

//��� �Լ��� link�� ��� �� �迭�� ��ġ�� ���� ó������ ���
void print_ans(int index){
	if(index==-1) return;
	print_ans(link[index]);
	cout<< arr[index] << ' ';
}

int main(){
	int n, end, ans = 0;
	//��� �� �к��� ���Ͽ� ��� �� -1�� �ʱ�ȭ
	fill(link, link+1000, -1);
	//�Է�
	cin >> n;
	for(int i = 0; i < n; i++){
		int max_num = 0; //���� �ִ� ���� ��ø �ȵǰ� �ִ� �� 0���� �ʱ�ȭ
		cin >> arr[i];
		for(int j = 0; j < i; j++){
			//���� �迭���� ���� ���� ���� ��� �� �ִ� ���̺��� ū ���
			if(arr[i] > arr[j] && max_num < d[j]){
				max_num = d[j]; //�ִ� ���� ���� �� 
				link[i] = j; //�ִ� ������ �迭 ���
			}

		}
		d[i] = max_num+1; //�ڱ� �ڽ��� �����ϹǷ� �ִ� ���� +1
		//��ü �Է°� �߿� �ִ� ���̸� ��� �� �ִ� ���� ���� �迭 ��ġ ���
		if(d[i] > ans){ 
			ans = d[i];
			end = i;
		}
	}
	//���
	cout<<ans<<'\n';
	print_ans(end);
}
