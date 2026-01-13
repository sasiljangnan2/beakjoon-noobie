#include <stdio.h>
#include <stdlib.h>
long long pow (long long a, long long b, int c)
{
	long long res = 1;
	if (b % 2 == 1)
		res = a % c;
	a = a % c;
	while (b /= 2)
	{
		a = (a * a) % c;
		if (b % 2 == 1) res = (res * a) % c;
	}
	return res % c;
}
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", pow(a, b, c));
}