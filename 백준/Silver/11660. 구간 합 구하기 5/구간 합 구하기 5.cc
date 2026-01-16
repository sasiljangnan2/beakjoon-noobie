#include <stdio.h>
#include <stdlib.h>
int main()
{
	int dp[1024][1024] = { 0 };
	int N, M, x1,x2, y1, y2, sum = 0, i, j, k;
	scanf("%d%d", &N, &M);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &dp[i][j]);
	for (i = 1; i < N; i++)
		dp[0][i] += dp[0][i - 1];
	for (i = 1; i < N; i++)
		dp[i][0] += dp[i - 1][0];
	for (i = 1; i < N; i++)
		for (j = 1; j < N; j++)
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

	for (i = 0; i < M; i++)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		sum = dp[x2 - 1][y2 - 1];
		if (x1 > 1)
			sum -= dp[x1 - 2][y2 - 1];
		if (y1 > 1)
			sum -= dp[x2 - 1][y1 - 2];
		if (x1 > 1 && y1 > 1)
			sum += dp[x1 - 2][y1 - 2];
		printf("%d\n", sum);
	}
}