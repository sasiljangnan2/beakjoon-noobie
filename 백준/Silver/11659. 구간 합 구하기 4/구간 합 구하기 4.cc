#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M, num, x, y, i, j, sum = 0;
	int* arr = (int*)malloc(100000 * sizeof(int));
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		sum += num;
		arr[i] = sum;
	}
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);
		if (x == 1) printf("%d\n", arr[y - 1]);
		else printf("%d\n", arr[y - 1] - arr[x - 2]);
	}
	free(arr);
}