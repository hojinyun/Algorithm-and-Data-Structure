#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, stop,arr[10001]={};
	//입력
	cin >> n;
	for(int i = 1; i <=n; i++) cin >> arr[i];
	
	//뒤에서부터 오름차순인지 확인 
	for(int i = n; i > 0; i--){
		//제일 처음 값까지 확인을 하러 온 것이면
		//더 이상 다음 순열이 존재하지 않차으므로 -1 출력 
		if(i==1){
			cout<<-1;
			break;
		}
		//멈춰야 되는 위치 찾기
		if(arr[i-1]>arr[i]){
			//바꿔야 되는 값을 찾음 
			int stop = i-1; //멈추는 위치 
			int max_idx=i; //멈춘 값보다 작은 값중 최대값 초기화
			//멈춘 위치부터 끝까지 모든 값 확인 
			for(int j = stop; j<=n; j++){
				//멈춘 값보다 작은 값중에 최대값 max_idx에 저장 
				if(arr[stop]>arr[j] && arr[j] > arr[max_idx]) min_idx = j;
			}
			
			//위치 바꾸고 멈추는 위치 이후 값 정렬 
			int temp;
			temp = arr[min_idx];
			arr[min_idx] = arr[i-1];
			arr[i-1] = temp;
			sort(arr+i,arr+n+1,greater<int>());
			//출력 
			for(int i = 1; i<= n; i++) cout<<arr[i]<<" ";
			break;
		}
	}
}

/* prev_permutation 사용 방식 
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, stop,arr[10001]={};
	//입력
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	//출력 
	if(prev_permutation(arr,arr+n)){
		for(int i = 0; i<n; i++) cout<<arr[i]<<" ";
	}
	else cout<<-1;
}
*/
