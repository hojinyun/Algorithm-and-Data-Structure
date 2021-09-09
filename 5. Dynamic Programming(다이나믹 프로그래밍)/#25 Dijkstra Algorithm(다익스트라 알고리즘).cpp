//시간 복잡도 O(N^2) getSmallIndex에서 for를 돌아야 돼서 비효율적 
/* 
#include <stdio.h>

int number = 6;
int INF = 1000000000;

// 전체 그래프를 초기화합니다.
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

bool v[6]; // 방문한 노드 
int d[6]; // 최단 거리

// 가장 최소 거리를 가지는 정점을 반환
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

// 다익스트라를 수행하는 함수
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

// 힙 구조를 이용한 시간복잡도 O(NlogN) 다익스트라 알고리즘
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;

vector<pair<int, int> > a[7]; // 간선 정보
int d[7]; // 최소 비용

void dijkstra(int start){
	d[start] = 0;
	priority_queue<pair<int, int> > pq; // 힙 구조
	pq.push(make_pair(0, start)); 
	// 가까운 순서대로 처리하므로 큐를 사용합니다. 
	while(!pq.empty()){
		// 짧은 것이 먼저 오도록 음수화(-) 합니다. 우선순위 큐는 큰게 맨 앞으로 옴 
		int distance = -pq.top().first; // 
		
		int current = pq.top().second; // 현재 방문 노드
		pq.pop();
		// 최단 거리가 아닌 경우 스킵합니다.
		if(d[current] < distance) continue;
		for(int i = 0; i < a[current].size(); i++) { // 현재 노드인 current와 연결 된 간선 모두 검사 
			// 선택 된 노드의 인접 노드
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
	//기본적으로 연결되지 않은 경우 비용은 무한입니다.
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


