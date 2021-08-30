#include <iostream>
using namespace std;

int main(){
	int i, j, temp;
	int array[10]={10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	for(i=0;i<9;i++){
		j=i;
		while(array[j]>array[j+1]){
			temp = array[j];
			array[j] = array[j+1];
			array[j+1] = temp;
			j--;
		}
	}	
	for(i=0; i<10; i++){
		cout<<array[i]<<" ";
	}
	return 0;
}
