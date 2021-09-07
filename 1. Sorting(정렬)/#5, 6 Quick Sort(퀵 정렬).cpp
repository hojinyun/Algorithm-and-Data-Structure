#include <iostream>
using namespace std;


int number = 10;
int data[10]={5, 9, 8, 7, 6, 10, 4, 3, 2, 1};

void quickSort(int *data, int start, int end){
	if(start >= end){ //원소가 1개인 경우 
		return;
	}
	int key = start; //키는 첫번째 원소 
	int i = start + 1;
	int j = end; 
	int temp;
	
	while(i <= j){ // 엇갈리 때가지 반복
		while(data[i] <= data[key]){  //키 값보다 큰 값을 만날때까지 오른쪽으로 이동 
			i++;	
		}
		while(data[j] >= data[key] && j > start){ //키 값보다  작은 값을 만날때까지 왼쪽으로 이동 
			j--;
		}
		if(i>j){ //현재 엇갈린 상태면 키 값과 교체 
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}
	
	quickSort(data, start, j-1);
	quickSort(data, j+1, end);
}


int main(){
	quickSort(data, 0, number - 1);
	
	for(int i=0; i<10; i++){
		cout<<data[i]<<" ";
	}
	return 0;
}
