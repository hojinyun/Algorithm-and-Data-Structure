#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, ans = 0, arr[1001], d[1001]={};
	cin >> n;
	for(int i = 0; i<n; i++){
		int max_num = 0;
		cin >> arr[i];
		for(int j = 0; j<i; j++){
			if(arr[i] > arr[j]) max_num = max(max_num, d[j]);
		}
		d[i] = max_num+1;
		ans = max(ans, d[i]);
	}
	
	cout << ans;
}
