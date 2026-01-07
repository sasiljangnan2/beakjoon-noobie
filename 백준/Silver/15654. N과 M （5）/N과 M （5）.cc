#include <stdio.h>
#include <stdlib.h>

int arr[9];
int temp[9];
int check[9];
int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
void dfs(int m, int n, int count)
{
	if (count == n)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= m; i++)
	{
		if (check[i] == 0)
		{
			check[i] = 1;
			arr[count] = temp[i - 1];
			check[i] = 1;
			dfs(m, n, count + 1);
			check[i] = 0;
		}
	}
}
int main()
{
	int M, N, i;
	scanf("%d %d", &M, &N);
	for (i = 0; i < M; i++) scanf("%d", &temp[i]);
	qsort(temp, M, sizeof(int), compare);
	dfs(M, N, 0);
}