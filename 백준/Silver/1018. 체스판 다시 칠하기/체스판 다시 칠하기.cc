#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int chess(char **arr, int N, int M)
{
	int i, j;
	int cnt = 0;
	for (i = N; i < N + 8; i++)
	{
		for (j = M; j < M + 8; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					if (arr[i][j] != 'W')
					{
						cnt++;
					}
				}
				else
				{
					if (arr[i][j] != 'B')
					{
						cnt++;
					}
				}
			}
			else
			{
				if (j % 2 == 0)
				{
					if (arr[i][j] != 'B')
					{
						cnt++;
					}
				}
				else
				{
					if (arr[i][j] != 'W')
					{
						cnt++;
					}
				}
			}
		}
	}
	if (cnt > 32)
	{
		cnt = 64 - cnt;
	}
	return cnt;
}
int main(void) 
{
	int i, j, cnt = 32, N, M;;
	scanf("%d %d", &N, &M);
	//char arr[51][51];
	char ** arr;
	arr = (char**)malloc(sizeof(char*) * (N + 1));
	for (i = 0; i < N; i++) 
	{
		arr[i] = (char*)malloc(sizeof(char) * (M + 1));
	}

	for (i = 0; i < N; i++) 
	{
		scanf("%s", arr[i]);
	}

	for (i = 0; i <= N - 8; i++) 
	{
		for (j = 0; j <= M - 8; j++) 
		{
			if (cnt > chess(arr, i, j)) cnt = chess(arr, i, j);
		}
	}
	printf("%d", cnt);
	return 0;
}



