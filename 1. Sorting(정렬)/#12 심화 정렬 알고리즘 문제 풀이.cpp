#include <iostream>
#include <algorithm>

using namespace std;

//------------------------ 1�� ���� <�ܾ� ����> ------------------------------

/*string word[20000];
int number;

bool compare(string a, string b){
	if (a.length() == b.length()){
		return a < b;
	}
	else{
		return a.length() < b.length(); 
	}
}

int main(void){
	cin >> number;
	for(int i = 0; i < number; i++){
		cin >> word[i];
	}
	
	sort(word, word+number, compare);
	for(int i = 0;  i < number; i++){
		if(i > 0 && word[i] == word[i-1]){
			continue;
		}
		else{
			cout << word[i] <<endl;
		}
	}
} */


//------------------------ 2�� ���� <�ø��� ��ȣ>----------------------------

/* string word[1000];
int number;

int getSum(string a){                      <--- �߰��� �� 
	int length = a.length(), sum = 0;
	for(int i = 0; i < length; i++){
		// ������ ��쿡�� ���մϴ�. 
		if(a[i] - '0' <= 9 && a[i] -'0' >= 0){
			sum +=a[i] - '0';
		}
	}
	return sum;
}

bool compare(string a, string b){
	if (a.length() == b.length()){         <--- �ٲ� ��  
		int aSum = getSum(a);
		int bSum = getSum(b);
		if(aSum == bSum){
			return a < b;
		}
		else{
			return aSum < bSum;
		}	
	}
	else{
		return a.length() < b.length(); 
	}
}

int main(void){
	cin >> number;
	for(int i = 0; i < number; i++){
		cin >> word[i];
	}
	
	sort(word, word+number, compare);
	for(int i = 0;  i < number; i++){      <--- �ٲ� �� 
		cout << word[i] <<endl;
	}
} */

//------------------------ 3�� ���� <�� �����ϱ� 3>----------------------------

int n;
int a[10001];

int main(void){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	
	for(int i = 0; i < 10001; i++){
		while(a[i] != 0){
			printf("%d\n", i);
			a[i]--;
		}
	}
	
}

 
