#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int main()
{
	
	int N, i, j, max;
	int arr[MAX];
	int dp[MAX] = { 0 };
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
	{
		scanf("%d", &arr[i]);
	}
	dp[0] = 1;
	for (i = 1; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
	}
	max = dp[0];
	for (i = 1; i < N; i++) 
	{
		if (dp[i] > max)
		{
			max = dp[i];
		}
	}
	printf("%d\n", max);
}