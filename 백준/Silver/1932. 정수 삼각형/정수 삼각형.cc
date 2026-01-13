#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, dp[500] ={0}, arr[500] = {0}, i, j, temp;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			scanf("%d", &temp);
			if (j == 0)
				arr[j] += temp;
			else if (j == i)
				arr[j] = dp[j - 1] + temp;
			else
			{
				if (dp[j - 1] > dp[j])
					arr[j] = dp[j - 1] + temp;
				else
					arr[j] += temp;
			}
		}
		for (j = 0; j < n; j++)
		{
			dp[j] = arr[j];
		}
	}
	int max = dp[0];
	for (i = 0; i < n; i++) 
	{
		if (dp[i] > max)
			max = dp[i];
	}
	printf("%d\n", max);
}