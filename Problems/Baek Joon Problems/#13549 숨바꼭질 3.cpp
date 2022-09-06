#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

int n=0, k=0;
int count[100001]={0};
deque<int> dq;

int main(){
	//�Է� 
	cin >> n >> k;
	dq.push_front(n);
	count[n]=1;
	while(!dq.empty()){
		if(dq.front()==k) break;
		
		int tmp = dq.front();
		dq.pop_front();
		//�����̵��� �� 
		if(2*tmp <= 100000 && !count[2*tmp]){
			dq.push_front(2*tmp);
			count[2*tmp] = count[tmp];
		}
		//������ ��ĭ �� �� 
		if(tmp+1 <= 100000 && !count[tmp+1]){
			dq.push_back(tmp+1);
			count[tmp+1] = count[tmp]+1;
	 	}
		 //�ڷ� ��ĭ �� �� 
		if(tmp-1 >= 0 && !count[tmp-1]){
			dq.push_back(tmp-1);
			count[tmp-1] = count[tmp]+1;
		}	
	}
	cout<<count[k]-1;
}
