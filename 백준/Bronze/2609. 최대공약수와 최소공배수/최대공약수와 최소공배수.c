#include <stdio.h>

int main(void)
{
	int a, b, i, n = 1;
	scanf("%d %d", &a, &b);
	for (i = 1; i <= a || i <= b; i++)
	{
		if (a % i == 0 && b % i == 0) n = i;
	}
	printf("%d\n%d", n, a * b / n);
}