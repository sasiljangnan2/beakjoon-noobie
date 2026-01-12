#include <stdio.h>
#include <stdlib.h>

int arr[9];

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
		
		if (count == 0 || arr[count - 1] <= i )
		{
			
			arr[count] = i;
			dfs(m, n, count + 1);
		}
	}
}
int main()
{
	int M, N, i;
	scanf("%d %d", &M, &N);
	dfs(M, N, 0);
}