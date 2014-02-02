#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 8, 4, 6, 1, 3, 2, 7};

 //5, 2, 4, 6, 1, 3, 2, 7 (a[3] = 6)
 //5, 2, 4, 7, 1, 3, 2, 6 (a[3] = 6)
 //5, 2, 4, 7, 1, 3, 2, 6 (a[3] = 6)
 //5, 2, 4, 1, 7, 3, 2, 6 (a[3] = 6)
 //5, 2, 4, 1, 3, 2, 7, 6 (a[3] = 6)
 //5, 2, 4, 1, 3, 2, 6, 7 (a[3] = 6)


void swap(int* n1, int* n2)
{
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}
int partition(int start, int end)
{
	/*
	 *从a[start..end]中选取一个pivot元素（比如选a[start]为pivot）;
	 *在一个循环中移动a[start..end]的数据，将a[start..end]分成两部分，
	 *使a[start..mid-1]比pivot元素小，a[mid+1..end]比pivot元素大，而a[mid]就是pivot元素;
	 */
	int mid = (start + end) / 2;
	int pivot_value = a[mid];
	swap(&a[mid], &a[end]);
	int pos = start;
	for ( int i = start; i < end ; ++i) {
		if (a[i] < pivot_value) {
			swap(&a[pos++], &a[i]);
		}
	}
	swap(&a[pos], &a[end]);
	printf(" to %d %d %d %d %d %d %d %d\n", 
	       a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
	return pos;
}

void quicksort(int start, int end)
{
	if (end > start) {
		int mid;
		mid = partition(start, end);
		quicksort(start, mid-1);
		quicksort(mid+1, end);
	}
}

int main(void)
{
	//sort(0, LEN-1);
	quicksort(0, LEN - 1);
	printf(" to %d %d %d %d %d %d %d %d\n", 
	       a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
	return 0;
}
