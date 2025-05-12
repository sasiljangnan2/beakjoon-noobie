#include <stdio.h>
#include <stdlib.h>
#define m 1234567891
int main(void) 
{
	int i, j, L;
	long long int  x = 1, temp = 0;
	char str[51];
	scanf("%d", &L);
	scanf("%s", &str);

	for (i = 0; i < L; i++) 
	{
		temp += x * (str[i] - 'a' + 1);
		temp %= m;
		x *= 31;
		x %= m;;
	}
	printf("%lld\n", temp);
	return 0;
}


