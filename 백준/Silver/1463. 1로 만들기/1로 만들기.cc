#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int DP[1000001] = { 0 };
	int i, num;
	scanf("%d", &num);
	for (i = 2; i <= num; i++)
	{
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0 && DP[i] > DP[i / 2] + 1) DP[i] = DP[i / 2] + 1;
		
		if (i % 3 == 0 && DP[i] > DP[i / 3] + 1) DP[i] = DP[i / 3] + 1;
	}
	printf("%d\n", DP[num]);
}