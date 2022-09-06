#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n=0, m=0, count[101][101]={0};
char map[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char tree[26][3];

void preorder(){
	
	tree[
}
void inorder(){
	
}
void postorder(){
	
}

int main(){
	//ют╥б 
	cin >> n;
	for(int i = 0; i < n; i++){
		char node, left_child, right_child;
		cin >> node >> left_child >> right_child;
		tree[i][0]=node;
		tree[i][1]=left_child;
		tree[i][2]=right_child;	
	}
	
	cout<<count[n][m];
}
