#include <stdio.h>

#define LEN 5
int a[LEN] = { 6, 5, 2, 4, 7 };
//10 5 2 4 7
//7 5 2 4 10
//5 7 2 4 10
//2 7 5 4 10
//2 4 5 7 10 


void insertion_sort(void)
{
	int i, j, key;

	for (i = 0 ; i < LEN; ++i) {

	printf("%d, %d, %d, %d, %d\n",
	       a[0], a[1], a[2], a[3], a[4]);
		key = a[i];
		for (j = 0; j < LEN; ++j) {
			if ( a[j] > key) {
				int tmp = key;
				a[i] = a[j];
				a[j] = tmp;
				break;
			}
		}
		if (j == LEN){
			int tmp = key;
			a[i] = a[j - 1];
			a[j-1] = tmp;
		}
	}
	printf("%d, %d, %d, %d, %d\n",
	       a[0], a[1], a[2], a[3], a[4]);
}

int main(void)
{
	insertion_sort();
	return 0;
}
