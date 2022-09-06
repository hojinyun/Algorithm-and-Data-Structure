#include <iostream>
#include <queue>

using namespace std;

int s=0, clipboard=0, display=1;
int count[2001][2001]={0};
queue<pair<int,int>> q;

int main(){
	//�Է� 
	cin >> s;
	q.push({clipboard,display});
	while(!q.empty()){
		clipboard = q.front().first;
		display = q.front().second;
		//cout<<"CLIPBOARD: "<<clipboard<<" DISPLAY: "<<display<<endl;
		q.pop();
		if(display==s){
			//cout<<"ARRIVED"<<endl;
			break;
		}
		//Ŭ�����忡 �����ϴ� ���
		if(count[display][display]<=0){
			//cout<<"COPY: "<<display<<endl;
			q.push({display, display});
			count[display][display] = count[clipboard][display]+1;
		}
		//�ٿ��ִ� ���
		if(count[clipboard][display+clipboard]<=0 && display+clipboard<=2000){
			//cout<<"PASTE: "<<clipboard<<endl;
			q.push({clipboard,display+clipboard});
			count[clipboard][display+clipboard] = count[clipboard][display]+1;
		}
		//�̸�Ƽ�� �ϳ��� �����ϴ� ��� 
		if(count[clipboard][display-1]<=0 && display-1>=0){
			//cout<<"DELETE: "<<display-1<<endl;
			q.push({clipboard,display-1});
			count[clipboard][display-1] = count[clipboard][display]+1;
		}
	}
	cout<<count[clipboard][display];
}
