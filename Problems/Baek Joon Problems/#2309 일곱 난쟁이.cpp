#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int sum=0, arr[9];
	//입력 및 모든 입력값의 합 저장
	for(int i = 0; i < 9; i++){
		cin >> arr[i];
		sum+=arr[i];
	}
	sort(arr,arr+9); //정렬
	//2가지 값들의 조합을 모두 sum에서 빼본 뒤 100이면 -1로 바꾼다
	for(int i = 0; i < 9; i++){
		for(int j = i+1; j < 9; j++){
			if(sum-arr[i]-arr[j]==100){
				arr[i] = arr[j] = -1;
				break; //같은 값이 여러개면 중복이 될 수 있으니 100이 되는 값이 나오면 바로 for문 탈출
			}
		}
		//같은 값이 여러개면 중복이 될 수 있으니 100이 되는 값이 나오면 바로 for문 탈출
		if(arr[i]==-1) break;
	}
	//빼야 되는 두 값을 제외한 뒤 출력
	for(int i = 0; i < 9; i++){
		if(arr[i] != -1) cout << arr[i] <<'\n';
	}
	
}
