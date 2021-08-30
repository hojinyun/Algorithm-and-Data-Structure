#include <stdio.h>

int number = 8;
int sorted[8]; //정렬 배열은 반드시 전역 변수로 선언

void merge(int a[], int m, int middle, int n){
	int i = m;
	int j = middle+1;
	int k = m;
	//작은 순더대로 배열에 삽입 
	while(i <=middle && j <= n){
		if(a[i]<a[j]){
			sorted[k]=a[i];
			i++;
		}
		else{
			sorted[k]=a[j];
			j++;
		}
		k++;
	}
	// 남은 데이터도 삽입
	if(i > middle){
		for(int t = j; t <= n; t++){
			sorted[k]=a[t];
			k++;
		}
	}
	else{
		for(int t = i; t <= middle; t++){
			sorted[k] = a[t];
			k++;
		}
	}
	
	//정렬 된  배열을 삽입 
	for(int t = m; t<=n; t++){
		a[t]=sorted[t];
	}	
}

void mergeSort(int a[],int m, int n){
	if(m < n){ //무한으로 안들어가게 해줌 ex) mergeSort(a, 2, 2) 들어오면 계속 2, 2로 들어감
		int middle = (m+n)/2;
		mergeSort(a, m, middle);
		mergeSort(a, middle+1, n);
		merge(a, m, middle, n);
	}
}

int main(){
	int array[number] = {10, 9, 8, 7, 6, 5, 4, 3};
	mergeSort(array,0,number-1);
	
	for(int i=0; i<number; i++){
		printf("%d ", array[i]);
	}
}
