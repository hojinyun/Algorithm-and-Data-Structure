#include <iostream>

using namespace std;

int sorted[1000000];

void merge(int numbers[], int start, int middle, int end){
	int i = start;
	int j = middle + 1;
	int k = start;
	 
	while(i <= middle && j <= end){
		//i와 j중 더 큰 것을 sorted[]에 순서대로 비교하면서 넣음 
		if(numbers[i] <= numbers[j]){
			sorted[k] = numbers[i];
			i++;
		} else{
			sorted[k] = numbers[j];
			j++;
		}
		k++;
	}
	//분할 된 한쪽이 먼저 넣어질 경우 남은 한쪽 데이터 다 넣음 
	if(i > middle){
		for(int temp = j; temp <= end; temp++){
			sorted[k] = numbers[temp];
			k++;
		}
	} else{
		for(int temp = i; temp <= middle; temp++){
			sorted[k] = numbers[temp];
			k++;
		}
	}
	
	//정렬 된 배열 삽입
	for(int temp = start; temp <= end; temp++){
		numbers[temp] = sorted[temp];
	}
	
}

void mergeSort(int numbers[], int start, int end){
	if(start < end){
		int middle = (start + end)/2;
		mergeSort(numbers, start, middle);
		mergeSort(numbers, middle+1, end);
		merge(numbers, start, middle, end);
	}
}




int main(void){
	int n;
	cin >> n;
	
	int numbers[n];
	int sorted[n];
	
	for(int i = 0; i < n; i++){
		cin >> numbers[i];
	}
	
	mergeSort(numbers, 0, n-1);
	
	for(int i = 0; i < n; i++){
		cout << numbers[i] << '\n';
	}
}
