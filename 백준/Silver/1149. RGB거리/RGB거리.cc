#include <stdio.h>
#include <stdlib.h>

int main()
{
	int DP[3] = { 0, };
	int i, num;
	int x, y, z, r, g, b;
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf("%d %d %d", &r, &g, &b);
		x = DP[0] + r;
		y = DP[1] + g;
		z = DP[2] + b;
		DP[0] = (y > z) ? z : y;
		DP[1] = (x > z) ? z : x;
		DP[2] = (x > y) ? y : x;
	}
	for (i = 0; i < 3; i++)
	{
		if (i == 0 || DP[i] < DP[0])
			DP[0] = DP[i];
	}
	printf("%d\n", DP[0]);
}