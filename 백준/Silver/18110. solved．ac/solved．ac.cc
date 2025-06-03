
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* arg1, const void* arg2)
{
	return (*(int*)arg1 - *(int*)arg2);
}

int main(void)
{
	int i, N, d;
	int* arr;
	double p;
	long long temp = 0;
	scanf("%d", &N);
	arr = (int*)malloc(N * sizeof(int));
	p = round( N / 100.0 * 15.0);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &d);
		arr[i] = d;
	}
	qsort(arr, N, sizeof(int), compare);
	for (i = (int)p; i < N - (int)p; i++)
	{
		temp += arr[i];
	}
	printf("%d", (long long)round(temp / (N - (2 * p))));
	return 0;
}
	
