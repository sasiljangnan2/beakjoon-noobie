#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int i, n, t, p, temp = 0;
	double size[6];
	scanf("%d", &n);
	for (i = 0; i < 6; i++)
	{
		scanf("%lf", &size[i]);
	}
	scanf("%d %d", &t, &p);
	for (i = 0; i < 6; i++)
	{
		temp += ceil(size[i] / t);
	}
	printf("%d\n", temp);
	printf("%d %d", n / p, n % p);


}