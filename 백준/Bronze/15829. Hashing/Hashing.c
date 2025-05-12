#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	int i, j, L, temp = 0, x;
	char str[51];
	scanf("%d", &L);
	scanf("%s", &str);

	for (i = 0; i < L; i++) 
	{
		x = 1;
		for (j = 0; j < i; j++)
		{
			x *= 31;
		}
		temp += x * (str[i] - 'a' + 1);
	}
	printf("%d\n", temp % 1234567891);
	return 0;
}


