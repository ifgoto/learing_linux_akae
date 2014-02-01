#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int a[N];
int histogram[10] = {0};

void gen_random(int upper_bound)
{
	srand(time(NULL));
	int i;
	for (i = 0; i < N; i++) {
		a[i] = rand() % upper_bound;
		histogram[a[i]]++;
	}
}

void print_random()
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void show_histogram()
{
	//print the header
	for (int i = 0; i < 10; ++i) {
		printf("%i\t", i);	
	}
	printf("\n");

	_Bool has_data = 1;
	//print the data
	while (has_data) {
		has_data = 0;
		for (int i = 0; i < 10; ++i) {
			if (histogram[i] > 0) {
				printf("*\t");
				has_data = 1;
			} else {
				printf(" \t");
			}
			--histogram[i];
		}
		printf("\n");
	}
}


int main(void)
{ 

	gen_random(10);
	//print_random();
	show_histogram();
	return 0;
}
