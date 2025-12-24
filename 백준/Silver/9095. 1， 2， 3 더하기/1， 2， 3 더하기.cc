#include <stdio.h>
#include <stdlib.h>

int main()
{
	int DP[11] = { 0, 1, 2, 4 };
	int i, T, n;
	scanf("%d", &T);
	for (i = 4; i < 11; i++) DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
	for (i = 0; i < T; i++)
	{
		scanf("%d", &n);
		printf("%d\n", DP[n]);
	}

}