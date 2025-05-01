#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int i, j, k, num[100], n, m, temp = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for(k = 0; k < n; k++)
			{
				if (i != j && j != k && i != k && temp < num[i] + num[j] + num[k] && num[i] + num[j] + num[k] <= m) temp = num[i] + num[j] + num[k];
			}
		}
	}
	printf("%d", temp);
}