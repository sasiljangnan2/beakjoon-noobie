#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef struct
{
	int weight;
	int value;
} backpack;
int main()
{
	backpack bp[101];
	int dp[101][100001] = { 0 };
	int N, K;
	int i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &bp[i].weight, &bp[i].value);
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 0; j <= K; j++) 
		{
			if (j - bp[i].weight >= 0)
			{
				dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - bp[i].weight] + bp[i].value);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	printf("%d\n", dp[N][K]);
}