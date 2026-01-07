#include <stdio.h>
#include <stdlib.h>

int arr[9];
int check[9];

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
			arr[count] = i;
			for (int j = 1; j <= i; j++) check[j] = 1;
			dfs(m, n, count + 1);
			for (int j = 1; j <= i; j++) check[j] = 0;
		}
	}
}
int main()
{
	int M, N;
	scanf("%d %d", &M, &N);
	dfs(M, N, 0);
}