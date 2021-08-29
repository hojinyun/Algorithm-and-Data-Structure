#include <stdio.h>

/*int array[3];

int main(){
	int number, i, j, min, temp, index;
	//scanf("%d", &number);
	for (i=0; i<3; i++){
		scanf("%d",&array[i]);
	}
	for (i=0; i<3; i++){
		min = 1000001;
		for (j=i; j<3; j++){
			if (array[j]<min){
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	
	for (i=0; i<3; i++){
		printf("%d ", array[i]);
	}
}*/

int number, data[1000001];

void quickSort(int *data, int start, int end){
	if (start >= end){
		return;
	}
	
	int key = start;
	int i = start+1;
	int j = end;
	int temp;
	
	while(i<=j){
		while(data[key]>=data[i]){
			i++;
		}
		while(data[key]<=data[j] && j > start){
			j--;
		}
		if (i>j){
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j-1);
	quickSort(data, j+1, end);
	
}

int main(){
	scanf("%d", &number);
	for (int i=0; i<number; i++){
		scanf("%d",&data[i]);
	}
	quickSort(data, 0, number-1);
	
	for (int i=0; i<number; i++){
		printf("%d\n", data[i]);
	}
}
