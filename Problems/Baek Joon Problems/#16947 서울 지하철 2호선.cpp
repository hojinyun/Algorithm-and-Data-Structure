#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool found_cycle = false;
int n=0, start_station = 0, total_distance[3001]={0};
bool visited[3001]={0}, cycle_station[3001]={0};
vector<int> station[3001];

void find_distance_bfs(){
	queue<pair<int,int>> q;
	for(int i = 1; i <= n; i++){
		if(cycle_station[i]) q.push({i,0});
	}
	while(!q.empty()){
		int current=q.front().first, distance=q.front().second;
		q.pop();
		visited[current] = true;
		for(int i = 0; i < station[current].size(); i++){
			int next_station = station[current][i];
			if(visited[next_station]||cycle_station[next_station]) continue;
			total_distance[next_station]=distance+1;
			q.push({next_station,distance+1});
		}
	}
}

void find_cycle_dfs(int station_num, int cnt){
//	cout<<"station: "<<station_num<<" count: "<<cnt<<endl;
	
	
	
	
	if(visited[station_num]){
	///	cout<<"VISITED"<<endl;
		return;
	}
	visited[station_num] = true;
	for(int i = 0; i < station[station_num].size(); i++){
		int next = station[station_num][i];
		//cout<<"NEXT STATION: "<<next<<endl;
		
		
		
		
		if(start_station == next && cnt>2){
			found_cycle=true;
			cycle_station[next]=true;
			//cout<<"FOUND CYCLE FROM "<< next<<endl;
			return;
		}
		if(visited[next]){
			//cout<<"ALREADY VISITED"<<endl;
			continue;
		}
		
		find_cycle_dfs(next,cnt+1);
		if(found_cycle){
			cycle_station[next]=true;
			//cout<<"GOING BACK FOUND CYCLE FROM "<< next<<endl;
			return;
		}
	}
	visited[station_num] = false;
}

int main(){
	//ют╥б 
	cin >> n;
	for(int i = 0; i < n; i++){
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		station[tmp1].push_back(tmp2);
		station[tmp2].push_back(tmp1);
	}
	/*
	for(int i = 1; i <= n; i++){
		//cout<<"station "<<i<<": ";
		for(int j = 0; j < station[i].size(); j++){
			cout<<station[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	for(int i = 1; i <= n; i++){
		if(visited[i] || found_cycle) continue;
		//cout<<i<<" "<<j<<endl;
		
		start_station = i;
	//	cout<<"start station: "<<start_station<<endl;
		find_cycle_dfs(i, 1);
	}
//cout<<"Cycle Station: ";
	//for(int i = 1; i <= n; i++){
	//	cout<<cycle_station[i]<<" ";
//	}
//	cout<<endl;
	
	memset(visited, false, 3000);
	
	find_distance_bfs();
	for(int i = 1; i <= n; i++) cout<<total_distance[i]<<" ";
	
}
