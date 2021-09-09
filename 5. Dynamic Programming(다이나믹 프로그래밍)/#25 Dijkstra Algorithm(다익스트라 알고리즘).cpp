//�ð� ���⵵ O(N^2) getSmallIndex���� for�� ���ƾ� �ż� ��ȿ���� 
/* 
#include <stdio.h>

int number = 6;
int INF = 1000000000;

// ��ü �׷����� �ʱ�ȭ�մϴ�.
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

bool v[6]; // �湮�� ��� 
int d[6]; // �ִ� �Ÿ�

// ���� �ּ� �Ÿ��� ������ ������ ��ȯ
int getSmallIndex(){
	int min = INF;
	int index = 0;
	for(int i = 0; i < number; i++){
		if(d[i] < min && !v[i]){
			min = d[i];
			index = i;
		}
	}
	return index;
} 

// ���ͽ�Ʈ�� �����ϴ� �Լ�
void dijkstra(int start){
	for(int i = 0; i< number; i++){
		d[i] = a[start][i];
	}
	v[start] = true;
	for(int i = 0; i < number - 2; i++){
		int current = getSmallIndex();
		v[current] = true;
		for(int j = 0; j < number; j++){
			if(!v[j]){
				if(d[current] + a[current][j] < d[j]){
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}

int main(void){
	dijkstra(0);
	for(int i = 0; i < number; i++){
		printf("%d ", d[i]);
	}
} */

// �� ������ �̿��� �ð����⵵ O(NlogN) ���ͽ�Ʈ�� �˰���
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;

vector<pair<int, int> > a[7]; // ���� ����
int d[7]; // �ּ� ���

void dijkstra(int start){
	d[start] = 0;
	priority_queue<pair<int, int> > pq; // �� ����
	pq.push(make_pair(0, start)); 
	// ����� ������� ó���ϹǷ� ť�� ����մϴ�. 
	while(!pq.empty()){
		// ª�� ���� ���� ������ ����ȭ(-) �մϴ�. �켱���� ť�� ū�� �� ������ �� 
		int distance = -pq.top().first; // 
		
		int current = pq.top().second; // ���� �湮 ���
		pq.pop();
		// �ִ� �Ÿ��� �ƴ� ��� ��ŵ�մϴ�.
		if(d[current] < distance) continue;
		for(int i = 0; i < a[current].size(); i++) { // ���� ����� current�� ���� �� ���� ��� �˻� 
			// ���� �� ����� ���� ���
			int nextDistance = distance + a[current][i].first;
			int next = a[current][i].second;
			
			if(nextDistance < d[next]){
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			} 
		}
	}
} 

int main(void){
	//�⺻������ ������� ���� ��� ����� �����Դϴ�.
	for(int i = 1; i<=number; i++){
		d[i] = INF;
	} 
	a[1].push_back(make_pair(2,2));
	a[1].push_back(make_pair(5,3));
	a[1].push_back(make_pair(1,4));
	
	a[2].push_back(make_pair(2,1));
	a[2].push_back(make_pair(3,3));
	a[2].push_back(make_pair(2,4));
	
	a[3].push_back(make_pair(5,1));
	a[3].push_back(make_pair(3,2));
	a[3].push_back(make_pair(3,4));
	a[3].push_back(make_pair(1,5));
	a[3].push_back(make_pair(5,6));
	
	a[4].push_back(make_pair(1,1));
	a[4].push_back(make_pair(2,2));
	a[4].push_back(make_pair(3,3));
	a[4].push_back(make_pair(1,5));
	
	a[5].push_back(make_pair(1,3));
	a[5].push_back(make_pair(1,4));
	a[5].push_back(make_pair(2,6));
	
	a[6].push_back(make_pair(5,3));
	a[6].push_back(make_pair(2,5));
	
	dijkstra(1);
	
	for(int i = 1; i <=number; i++){
		printf("%d ", d[i]);
	}
	
	
}


