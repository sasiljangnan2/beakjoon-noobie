#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main(void)
{
	int N, X, i, index = 0;
	int arr[1000000];
	int qarr[1000000];
	int sort[1000000];
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &X);
		arr[i] = X;
		qarr[i] = X;
	}
	qsort(qarr, N, sizeof(int), compare);
	sort[0] = qarr[0];
	for (i = 1; i < N; i++)
	{
		if (qarr[i] != qarr[i - 1])
		{
			index++;
			sort[index] = qarr[i];
		}
	}
	for (i = 0; i < N; i++)
	{
		int left = 0, right = index, mid;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (arr[i] == sort[mid])
			{
				printf("%d ", mid);
				break;
			}
			else if (arr[i] < sort[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
	}
}	