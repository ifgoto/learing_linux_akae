#include <stdio.h>
#define N 4
#define T 2
#define IS_COMBINATION 1

int arr[N];

void printArr(void){
	int j = T,i ;
	if(IS_COMBINATION){
		for(i=0;i<T-1;i++){
			if(arr[i]>arr[i+1])return;
		}
	}
	for(i=0;i<j;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void swap(int i , int j){
	int temp = arr[i];
	(arr[i]=arr[j]);
	arr[j]=temp;
}

void permutation(int k){
	int i = N-k;
	if(k==N-T){
		printArr();
		return;
	}
	for(;i<N;i++){
		swap(N-k,i);
		permutation(k-1);
		swap(N-k,i);
	}
}

int main(void){
	int i = 0 ;
	for(;i<N;i++ ){arr[i]=i+1;}
	permutation(N );
	return 1;
}
