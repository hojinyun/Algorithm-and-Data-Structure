#include <iostream>

using namespace std;

int arr[1000], d[1000]={}, link[1000]={};

//재귀 함수로 link에 기록 된 배열의 위치를 제일 처음부터 출력
void print_ans(int index){
	if(index==-1) return;
	print_ans(link[index]);
	cout<< arr[index] << ' ';
}

int main(){
	int n, end, ans = 0;
	//출력 시 분별을 위하여 모든 값 -1로 초기화
	fill(link, link+1000, -1);
	//입력
	cin >> n;
	for(int i = 0; i < n; i++){
		int max_num = 0; //이전 최대 값과 중첩 안되게 최대 값 0으로 초기화
		cin >> arr[i];
		for(int j = 0; j < i; j++){
			//현재 배열보다 작은 값인 경우와 기록 된 최대 길이보다 큰 경우
			if(arr[i] > arr[j] && max_num < d[j]){
				max_num = d[j]; //최대 길이 재기록 및 
				link[i] = j; //최대 길이의 배열 기록
			}

		}
		d[i] = max_num+1; //자기 자신을 포함하므로 최대 길이 +1
		//전체 입력값 중에 최대 길이를 기록 및 최대 값을 가진 배열 위치 기록
		if(d[i] > ans){ 
			ans = d[i];
			end = i;
		}
	}
	//출력
	cout<<ans<<'\n';
	print_ans(end);
}
