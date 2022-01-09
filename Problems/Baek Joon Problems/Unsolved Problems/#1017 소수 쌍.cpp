#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[25];
int matchA[25] = {-1, }, matchB[25] = {-1,};
bool visited[25] = {false,};

bool dfs(int a){
	if(visited[a]) return false;
	visited[a] = true;
	for(int b: adj[a]){
		if(matchB[b] == -1||dfs(matchB[a])){
			matchA[a]=b;
			matchB[b]=a;
			return true;
		}
	}
	return false;
}

int main(void){
	int n;
	cin >> n;
	vector<int> A, B;
	bool first_value_odd = false;
	for(int i = 0; i<n; i++){
		int number;
		cin >> number;
		//divide even or odd
		if(i==0 && number % 2) first_value_odd = true;
		(number%2 ? A, B).push_back(number);
	}
	
	if(A.size() != B.size()){
		cout<<-1;
		return 0;
	}
	
	if(!first_value_odd) swap(odd, even);
	
	//sieve of eratosthenes
	bool isPrime[1000] = {true,}
	for(int i = 3; i<2000; i++){
		if(!isPrime([i/2]) continue;
		for(int j = i*i; j<2000; j+=i*2){
			isPrime[j/2] = false;
		}
	}
	
	vector<int> result;
	//bipartite matching
	for(int i: adj[0]){
		int flow = 1;
		matchA[0] = i;
		matchB[i] = 0;
		for(int j=1; j<listSize; j++){
			visited[0] = true;
			if(dfs(j)) flow++;
		}
	}
	if(result.empty()) puts("-1");
    else{
        sort(result.begin(), result.end());
        for(int r: result)
            printf("%d ", r);
    }
}
